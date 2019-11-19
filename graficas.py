import numpy as np
import matplotlib.pylab as plt

datosEuler =np.loadtxt("Euler.dat")

t=datosEuler[:,0]
x=datosEuler[:,1]
v=datosEuler[:,2]

plt.figure()
plt.subplot(1,2,1)
plt.plot(t,x)
plt.subplot(1,2,2)
plt.plot(x,v)
plt.savefig("Euler.png")



datosRK4=np.loadtxt("Rungekutta4.dat")

t2=datosRK4[:,0]
x2=datosRK4[:,1]
v2=datosRK4[:,2]

plt.figure()
plt.subplot(1,2,1)
plt.plot(t2,x2)
plt.subplot(1,2,2)
plt.plot(x2,v2)
plt.savefig("Rungekutta4.png")