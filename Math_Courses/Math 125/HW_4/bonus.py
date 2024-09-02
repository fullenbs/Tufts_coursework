import numpy as np
import math
import matplotlib.pyplot as plt

x = np.linspace(-1, 1, 100)

f = np.sin(x)
fhat = 0.88*x

max = 0
for i in range(0, len(f)):
    temp = np.abs(f[i]-fhat[i])
    if max < temp:
        min = temp
print(min)

plt.title('Chebyshev basis Least Squares')
plt.plot(x, fhat, color='red', label='0.88x')
plt.plot(x, f, label="sin(x)")
leg = plt.legend(loc = 'upper left')
plt.show()