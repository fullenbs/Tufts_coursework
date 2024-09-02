import matplotlib.pyplot as plt
plt.style.use('seaborn-whitegrid')
import numpy as np

fig = plt.figure()
ax = plt.axes()

f = lambda x: (2*x-1)**(1/3)

plt.xlabel("kth iteration")
plt.ylabel("X(k)")

i = 0
x_0 = 1.01
epsilon = 0.00001
while i < 500:
    x_1 = f(x_0)
    plt.scatter(i, f(x_0), c = 'blue', edgecolors='none')
    if np.abs(x_0 - x_1) < epsilon:
        break
    x_0 = x_1
    i += 1
print(x_1)
plt.show()

