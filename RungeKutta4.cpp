
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


static const double K = 100;
static const double M = 2;
static const double lamb = 1;
static const double dt = 0.01;


double f0(double t, double y0, double y1); // deriva y0
double f1(double t, double y0, double y1); // deriva y1
void rungekutta4(double t, double h, double & y0, double & y1); 


int main(void)
{
  double x;
  double v;
  double t;
  x = 1;
  v = 0;
    
    ofstream outfile;
    outfile.open("Rungekutta4.dat");
    
  for(t = 0; t <= 10; t += dt)
  {
    outfile << t << " " << x << " " << v << endl ;
    rungekutta4(t, dt, x, v);
  }
        outfile.close();


  return 0;
}


//F0 y f1 dadas previamente.

double f0(double t, double y0, double y1)
{
  return y1;
}

double f1(double t, double y0, double y1)
{
  return (-K/M)*pow(y0, lamb);
}

//RK4 como se plantea en las diapositivas.

void rungekutta4(double t, double h, double & y0, double & y1)
{
  double k10, k11, k20, k21, k30, k31, k40, k41;
  k10 = h*f0(t, y0, y1);
  k11 = h*f1(t, y0, y1);
  k20 = h*f0(t+h/2, y0 + k10/2, y1 + k11/2);
  k21 = h*f1(t+h/2, y0 + k10/2, y1 + k11/2);
  k30 = h*f0(t+h/2, y0 + k20/2, y1 + k21/2);
  k31 = h*f1(t+h/2, y0 + k20/2, y1 + k21/2);
  k40 = h*f0(t + h, y0 + k30, y1 + k31);
  k41 = h*f1(t + h, y0 + k30, y1 + k31);

  y0 = y0 + (1.0/6.0)*(k10 + 2*k20 + 2*k30 + k40);
  y1 = y1 + (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
}