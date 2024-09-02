import numpy as np
import math
import matplotlib.pyplot as plt

#Data
asc = np.array([0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330]).astype('float64')
dec = np.array([408, 89, -66, 10, 338, 807, 1238, 1511, 1583, 1462, 1183, 804])

#Data setup for part a
x1 = np.zeros(12)
x2 = np.zeros(12)
for i in range(0, len(x1)):
    k = (2*math.pi*asc[i])/360
    x1[i] = np.cos(k)
    x2[i] = np.sin(k)

#Does intial setup for part b
x3 = np.zeros(12)
x4 = np.zeros(12)
for i in range(0, len(x3)):
    k = (4*math.pi*asc[i])/360
    x3[i] = np.cos(k)
    x4[i] = np.sin(k)

#Least squares function for part a
def part1(x1, x2, dec):
    cons = np.ones(12)
    At = np.vstack((cons, x1, x2))
    A = np.transpose(At)
    LHS = np.matmul(At, A)
    RHS = np.matmul(At, dec)
    return np.linalg.solve(LHS, RHS)

#Least squares function for part 2
def part2(x1, x2, x3, x4, dec):
    cons = np.ones(12)
    At = np.vstack((cons, x1, x2, x3, x4))
    A = np.transpose(At)
    LHS = np.matmul(At, A)
    RHS = np.matmul(At, dec)
    return np.linalg.solve(LHS, RHS)

def part3(asc, dec):
    At = np.ones(12)
    for k in range(1, 6):
        k = (2*i*math.pi*asc)/360
        x_s = np.sin(k)
        x_c = np.cos(k)
        At = np.vstack((At, x_c, x_s))
    At = np.vstack((At, np.cos((12*np.pi*asc)/360)))
    A = np.transpose(At)
    LHS = np.matmul(At, A)
    RHS = np.matmul(At, dec)
    return np.linalg.solve(LHS, RHS)

def graph_3(r, x):
    k_1 = (x*2*np.pi)/360
    k_2 = (x*4*np.pi)/360
    k_3 = (x*6*np.pi)/360
    k_4 = (x*8*np.pi)/360
    k_5 = (x*10*np.pi)/360
    k_6 = (x*12*np.pi)/360
    K = np.vstack((k_1, k_2, k_3, k_4,k_5,k_6))
    graph = r[0] + r[11]*np.cos(k_6)
    for i in range(0, 6):
        graph = graph + r[i+1]*np.cos(K[i])+r[i+2]*np.sin(K[i])
    return graph


#res = part1(x1, x2, dec)
#print(res)
res_2 = part2(x1, x2, x3, x4, dec)
print(res_2)
#r = part3(asc, dec)
#x = np.linspace(0, 360, 1000)
#res_3 = np.fft.fft(dec)
#print(res_3)

plt.title('Part 3 Orbit of Pallas Regression')
plt.xlabel('Ascension (degrees)')
plt.ylabel('Descension (minutes)')
#plt.scatter(asc, dec, color = 'blue')
#plt.plot(x, res[0]+res[1]*np.cos(k)+res[2]*np.sin(k), color ='red')
plt.savefig('Part 1 Regression')
plt.plot(x, res_2[0] + res_2[1]*np.cos(k)+res_2[2]*np.sin(k)+res_2[3]*np.cos(k_2)+ res_2[4]*np.sin(k_2), color='red')
#plt.savefig('Part_2')

plt.show()