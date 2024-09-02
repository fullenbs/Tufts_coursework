import csv
import numpy as np
import matplotlib.pyplot as plt

x = np.zeros(401) #Setup
x2 = np.zeros(401)
y = np.zeros(401)
count = 0
fig, ax = plt.subplots()

#Reads in file
with open('least_squares_data.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        x[count] = float(row[0])
        x2[count] = float(row[0])**2
        y[count] = float(row[1])
        count += 1

#Linear regression
def linear(x, y):
    A1 = np.ones(401) #Sets up matrix equation
    supA = np.vstack((A1, x))
    A = np.transpose(supA)
    bigA = np.matmul(supA, A)
    YA = np.matmul(supA, y)
    return np.linalg.solve(bigA, YA) #Returns coefficients

#Quadratic regression
def quad(x, x2, y):
    A1 = np.ones(401) #Sets up matrix equation
    supA = np.vstack((A1, x, x2))
    A = np.transpose(supA)
    bigA = np.matmul(supA, A)
    YA = np.matmul(supA, y)
    return np.linalg.solve(bigA, YA) #Returns coefficients

line = linear(x, y)
quadr = quad(x, x2, y)

plt.title('Regressions!')
x_space = np.linspace(-1, 3, 200)
plt.scatter(x, y, color = 'gray', s = 15)
plt.plot(x_space, line[0] + line[1]*x_space, color = 'red', linewidth=3, label = 'linear')
plt.plot(x_space, quadr[0] + x_space*quadr[1] + x_space**2*quadr[2], color ='blue', linewidth=3, label='quadratic')
leg = ax.legend(loc = 'upper left')
plt.show()