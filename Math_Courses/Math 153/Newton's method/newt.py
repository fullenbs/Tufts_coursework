import math
import numpy as np
import itertools
import matplotlib.pyplot as plt
#Finds nth root of any positive number

fig, axis = plt.subplots()
num = -1

def f(x):
    return np.e**x - x*np.e**x

def df(x):
    return -x*np.e**x

x = 1.1
epsilon = .000000000001

for i in range(1000): #Newton's method in action
    axis.scatter(i, x, color = "blue")
    x1 = x - f(x, root, num)/df(x, root)
    t = abs(x1 - x)
    if t < epsilon:
        print("Steps to converge: " + str(i+1))
        break
    x = x1
    i += 1
plt.show()