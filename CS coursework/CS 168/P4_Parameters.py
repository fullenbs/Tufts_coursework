import numpy as np
import matplotlib.pyplot as plt
import cvxpy as cp

np.random.seed(1)

T = 96
t = np.linspace(1, T, num=T).reshape(T,1)
p = np.exp(-np.cos((t-15)*2*np.pi/T)+0.01*np.random.randn(T,1))
u = 2*np.exp(-0.6*np.cos((t+40)*np.pi/T) - 0.7*np.cos(t*4*np.pi/T)+0.01*np.random.randn(T,1))
Q = 35
C = 3
D = -3
I = np.eye(96)
c = cp.Variable(T)

prob = cp.Problem(cp.Minimize(p.T(u+c)), 
                  [-D @ I <= c <= C @ I])

prob.solve()
print(prob.value, c.value)
# plt.figure(1)
# plt.plot(t/4, p); 
# plt.plot(t/4, u, 'r'); 
# plt.show()