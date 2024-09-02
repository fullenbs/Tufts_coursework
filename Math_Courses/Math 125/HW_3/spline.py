import numpy as np
import csv
import matplotlib.pyplot as plt

x = np.zeros(59)
y = np.zeros(59)
count = 0

#Reads in csv file and data
with open('spline_data.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        x[count] = float(row[0])
        y[count] = float(row[1])
        count += 1

#Creates triangle matrix
arr = np.zeros((59, 59))
for i in range(0, 59): #Build triangular matrix
    if i == 0:
        arr[0, 0] = 2
        arr[0, 1] = 1
    elif i == 58:
        arr[58, 58] = 2
        arr[58, 57] = 1
    else:
        arr[i, i - 1] = 1
        arr[i, i] = 4
        arr[i, i + 1] = 1

y_new = np.zeros(59) #Creates y-vector
y_new[0] = 3*(y[1]-y[0]) 
for i in range(1, 58):
    y_new[i] = 3*(y[i+1] - y[i-1])
y_new[58] = 3*(y[58] - y[57])

D = np.matmul(np.linalg.inv(arr), y_new) #Finds vector of derivatives

a = y #Gets coefficients for each spline
b = D
c = np.zeros(59)
d = np.zeros(59)
for i in range(0, 58):
    c[i] = 3*(y[i+1]-y[i]) - 2*D[i]-D[i+1]
    d[i] = 2*(y[i] - y[i+1]) + D[i] + D[i+1]

t = x
for i in range(0, 58): #Converts to correct interval then graphs
    t_bar = 0
    if  t[i] < t[i+1]:
        t_bar = np.linspace(t[i], t[i+1], 100)
    else:
        t_bar = np.linspace(t[i+1], t[i], 100)
    z = (t_bar - t[i])/(t[i+1]-t[i])
    plt.plot(t_bar, a[i]+b[i]*z+c[i]*(z**2)+d[i]*(z**3), color = 'red')

plt.grid() #Display stuff
plt.title('Spline interpolation')
plt.show()