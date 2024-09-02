import numpy as np
from scipy import integrate
import matplotlib.pyplot as plt
from scipy.integrate import odeint

a = 1.
b = 0.1
c = 1.5
d = 0.75
def dX_dt(X, t=0):
    return np.array([a*X[0] - b*X[0]*X[1], -c*X[1] + d*b*X[0]*X[1]])


pop_vector = [5, 10]
time = np.linspace(0, 15, 10000)

sol = odeint(dX_dt, pop_vector, time)
plt.plot(time, sol[:, 0], 'b', label = 'rabbits')
plt.plot(time, sol[:, 1], color = 'red', label = 'foxes')
plt.legend(loc='best')
plt.xlabel('Time')
plt.ylabel('Population')
plt.show()

############################## Mesh Grid $######################################
print("QUESTION 5 BELOW")
x = np.array([])
y = np.array([])
for i in range(0, 25):
    k = np.random.uniform(0, 60)
    j = np.random.uniform(0, 40)
    x = np.append(x, k)
    y = np.append(y, k)

#xv, yv = np.meshgrid(x, y, indexing = 'ij')
#u = a*xv - b*xv*yv
#u = np.linalg.norm(u)
#v = -c*yv+d*b*xv*yv
#v = np.linalg.norm(v)
#plt.quiver(x, y, u, v)
#plt.show()