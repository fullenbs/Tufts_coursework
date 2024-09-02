import csv
import numpy as np
import math
from matplotlib import pyplot as plt
import numpy.linalg as la

def parse_csv(filename, column):
    data = np.array([])
    line_count = 0
    with open(filename) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
            if line_count == 0:
                line_count += 1
            else:
                line_count += 1
                data = np.append(data, float(row[column]))
    return data

def year_gen(a, b):
    years = np.array([])
    for i in range (a, b):
        years = np.append(years, i)
    return years

#Plots data and gets best fit
def plot_data(x, y, y2, y3, col1, col2):
    fig, ax = plt.subplots(figsize=(12, 6))
    lin = np.linspace(1920, 2025, 1000)
    plt.subplot(2, 2, 1)
    plt.title('tempo vs time')
    plt.plot(x, y, col1)
    coeff = lin_fit(x,y)
    print(coeff[0], coeff[1])
    plt.plot(lin, coeff[1] + coeff[0]*lin)

    plt.subplot(2, 2, 2)
    plt.title('danceability vs time')
    plt.plot(x, y2, col2)
    coeff = lin_fit(x,y2)
    print(coeff[0], coeff[1])
    plt.plot(lin, coeff[1] + coeff[0]*lin, color = 'red')

    plt.subplot(2, 2, 3)
    plt.title('volume vs time')
    plt.plot(x, y3, col2)
    coeff = lin_fit(x, y3)
    plt.plot(lin, coeff[1] + coeff[0]*lin, color = 'green')
    fig.tight_layout(pad=1.0)
    #plt.show()


def lin_fit(x,y):
    # solve the least squares problem
    A = np.array([[xx,1] for xx in x])
    ls=la.lstsq(A,y,rcond=None)

    # get the coefficients and report them
    alpha,beta = ls[0]
    print(f"L(x) = {alpha:.03}*x + {beta:.03}")
    res = np.array([alpha, beta])
    # return the linear function determined by these coefficients
    return res
    
#Looks at time vs temp
tempo = parse_csv('data_by_year.csv', 4)
dance = parse_csv('data_by_year.csv', 1)
vol = parse_csv('data_by_year.csv', 5)
acoust = parse_csv('data_by_year.csv', 7)
years = year_gen(1921, 2021)
plot_data(years, tempo, dance, vol, 'bo', 'ro')


def calc_alpha(dates, temp):
   
    alpha_1 = 0
    for i in dates:
        alpha_1 = alpha_1 + dates**2
    alpha_2 = 0
    for i in temp:
        print(i)
        alpha_2 = alpha_2 + np.log(1/i - 1)
    alpha_3 = 0
    for i in temp:
        alpha_3 = alpha_3 + np.log(1/i - 1)
    alpha_4 = 0
    count = 0
    for i in temp:
        alpha_4 = alpha_4 + np.log(1/i - 1)*dates[i]
    count = count + 1
    denom = len(temp)* alpha_1 - alpha_3**2
    num = alpha_1*alpha_2 - alpha_3*alpha_4
    return num/denom


calc_alpha(years, acoust)