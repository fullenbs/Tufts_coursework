from matplotlib import pyplot as plt 
import numpy as np

fig = plt.figure()

x1 = np.random.uniform(0, 10, 20000)


y1 = []
mu, sigma = 0, 0.01
for x in x1:
    temp = np.random.normal(mu, sigma, 1)
    plt.scatter(x, 3*x+4 + temp, color = 'blue')
    y = 3*x+4 + temp
    y = float(y)
    #print(x, ",")
    #y1.append(y)


print("------------------")
print("------------------")
print("------------------")
print("------------------")
print("------------------")

for y in y1:
    print(y, ",")


plt.plot(x1, 3*x1 + 4, color = 'red')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Standard deviation of 0.01, 2000 samples')
plt.show()