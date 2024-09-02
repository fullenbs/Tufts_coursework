import csv
import numpy as np
import math
import numpy.linalg as la
from sklearn import svm
from matplotlib import pyplot as plt
import tensorflow as tf

#parse_csv times three
def parse_csv(filename, column, genre):
    data = np.array([])
    line_count = 0
    count = 0
    with open(filename) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
            if line_count == 0:
                line_count += 1
            else:
                try: 
                    if (row[16] == genre):
                        count = count + 1
                        data = np.append(data, float(row[column]))
                except:
                    count  = count + 1
    return data

def make_arr(genre, col1, col2):
    col1_data = parse_csv('artist_genre.csv', col1, genre)
    col2_data = parse_csv('artist_genre.csv', col2, genre)
    return np.transpose(np.vstack((col1_data, col2_data)))


jazz_data = make_arr('Jazz', 3, 4)
elec_data = make_arr('Electronic', 3, 4)
r_data = make_arr('Religious', 3, 4)

plt.scatter(jazz_data[:,0], jazz_data[:,1], color = 'b')
plt.scatter(elec_data[:,0], elec_data[:,1], color = 'r')
plt.scatter(r_data[:,0], r_data[:,1], color = 'g')
plt.show()

size = len(elec_data) + len(jazz_data) + len(r_data)
c = np.zeros(size)
count = 0
for i in c:
    if count < len(jazz_data):
        c[count] = 2
    elif count < len(elec_data) + len(jazz_data):
        c[count] = 1
    count = count + 1

count = 0
d = np.zeros((size, 2))
for i in d:
    if count < len(jazz_data):
        d[count] = jazz_data[count]
    elif count < len(jazz_data) + len(elec_data):
        d[count] = elec_data[count - (len(jazz_data) + len(elec_data))]
    else:
        d[count] = r_data[count - (len(jazz_data) + len(elec_data))]
    count = count + 1

print(d)
mM = svm.SVC()
mM.fit(d, c)
print(mM.predict([[0.9, 0.1], [0.9, 0.1]]))
