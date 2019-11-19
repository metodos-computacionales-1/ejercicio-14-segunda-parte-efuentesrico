#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double f0(double t, double y0, double y1); //Returns derivative of y0
double f1(double t, double y0, double y1); //Returns derivative of y1

static const double K = 50;
static const double M = 2;
static const double lamb = 1;
static const double dt = 0.01;

int main(void)
{
    float t=0.0;
    float v=0.0;
    float x=1.0;
    int iteraciones = 1000;
    
    ofstream outfile;
    outfile.open("Euler.dat");
    for(int i=0;i<iteraciones;i++){
        
      double t_now = t + i*dt;
      double x_before =x;
      double v_before =v;
      x = x + dt * f0(t_now,x_before,v_before);
      v = v + dt * f1(t_now,x_before,v_before);
      outfile << t_now << " " << x << " " << v << endl ;
      
    }
    
    outfile.close();
    
    return 0;
}

double f0(double t, double y0, double y1)
{
  return y1;
}

double f1(double t, double y0, double y1)
{
  return (-K/M)* std::pow (y0, lamb);
}