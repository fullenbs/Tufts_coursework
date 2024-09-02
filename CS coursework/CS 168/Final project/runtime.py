import csv
import numpy as np
import matplotlib.pyplot as plt


#This function generates the plot comparing different run time speeds. 
def speed_compare_results():

    #Initialization of variables and sizes
    emd_vals = np.zeros(7000)
    sink_vals_1 = np.zeros(7000)
    sink_vals_12 = np.zeros(7000)
    size = np.array((64, 128, 256, 512, 1024, 2048, 4096))
    size_list = [64, 128, 256, 512, 1024, 2048, 4096]

    #Due to my implementation, the results for lambda=1 and lambda=12 are stored
    #in different files. This reads them in and stores them.
    with open('time3.txt') as file:
        csvreader = csv.reader(file, delimiter=',')
        i = 0
        for row in csvreader:
            emd_vals[i] = row[0]
            sink_vals_1[i] = row[1]
            i += 1
    #Only care about run time for Sinkhorn for simplicity, the EMD should be 
    #close enough.
    with open ('time4.txt') as file:
        csvreader = csv.reader(file, delimiter=',')
        i = 0
        for row in csvreader:
            sink_vals_12[i] = row[1]
            i += 1

    #Array to keep track of average at each size, which is what is displayed in
    #the plot.
    emd_avg = np.zeros(7)
    sink_1_avg = np.zeros(7)
    sink_12_avg = np.zeros(7)

    #Probably a shorter way to do this, but this for loop gets the average.
    for i in range(7000):
        if i < 1000:
            emd_avg[0] += emd_vals[i]
            sink_1_avg[0] += sink_vals_1[i]
            sink_12_avg[0] += sink_vals_12[i]
        elif i < 2000:
            emd_avg[1] += emd_vals[i]
            sink_1_avg[1] += sink_vals_1[i]
            sink_12_avg[1] += sink_vals_12[i]
        elif i < 3000:
            emd_avg[2] += emd_vals[i]
            sink_1_avg[2] += sink_vals_1[i]
            sink_12_avg[2] += sink_vals_12[i]
        elif i < 4000:
            emd_avg[3] += emd_vals[i]
            sink_1_avg[3] += sink_vals_1[i]
            sink_12_avg[3] += sink_vals_12[i]
        elif i < 5000:
            emd_avg[4] += emd_vals[i]
            sink_1_avg[4] += sink_vals_1[i]
            sink_12_avg[4] += sink_vals_12[i]
        elif i < 6000:
            emd_avg[5] += emd_vals[i]
            sink_1_avg[5] += sink_vals_1[i]
            sink_12_avg[5] += sink_vals_12[i]
        elif i < 7000:
            emd_avg[6] += emd_vals[i]
            sink_1_avg[6] += sink_vals_1[i]
            sink_12_avg[6] += sink_vals_12[i]

    #Take the average at the end
    emd_avg = emd_avg/1000
    sink_1_avg = sink_1_avg/1000
    sink_12_avg = sink_12_avg/1000

    #Makes the plot and then saves it
    default_x_ticks = range(len(size_list))
    plt.plot(size.astype('str'), emd_avg, label='EMD', marker='.', color='orange')
    plt.plot(size.astype('str'), sink_1_avg, label='Sinkhorn, λ=1', marker='.', color='blue')
    plt.plot(size.astype('str'), sink_12_avg, label='Sinkhorn, λ=12', marker='.', color='cyan')
    plt.xlabel('Dimension of Histogram')
    plt.ylabel('Average run time (seconds)')
    plt.title('Run time comparison between Sinkhorn and EMD')
    plt.grid()
    legend = plt.legend(loc='upper left', fontsize='10')
    plt.savefig('speed compare results')

#Generates the box plot from the paper
def accuracy_compare_results():
    #Variable initialization
    emd_vals = np.zeros(10000)
    sink_vals = np.zeros(10000)
    rel_error_vals = np.zeros(10000)
    lambdas = np.array((1, 2, 4, 8, 12, 16, 24, 32, 48, 64))
    lambas_list = [1, 2, 4, 8, 12, 16, 24, 32, 48, 64]

    #Reads in values from the text file
    with open('res.txt') as file:
        csvreader = csv.reader(file, delimiter=',')
        i = 0
        for row in csvreader:
            emd_vals[i] = row[0]
            sink_vals[i] = row[1]
            rel_error_vals[i] = row[2]
            i += 1
    emd_avg = np.zeros(10)
    sink_avg = np.zeros(10)
    rel_error_avg = np.zeros(10)

    #This reasds in relative error into the form of a matrix, so that it can be
    #passed into box plot.
    V = np.zeros((1000, 10))
    for j in range(10):
        V[:,j] = rel_error_vals[j*1000:(j+1)*1000]
    
    #Makes and then saves the box plot.
    bp = plt.boxplot(V, flierprops={'marker': '.', 'markerfacecolor': 'white'},
                    medianprops={'color': 'red'})
    plt.xticks([1,2, 3, 4, 5, 6, 7, 8, 9, 10], lambas_list)
    default_x_ticks = range(len(lambas_list))
    plt.ylim(-.5, 6)
    plt.xlabel('λ value')
    plt.ylabel('(Sinkhorn - EMD)/EMD')
    plt.title('Box plot of relative error')
    plt.grid()
    plt.savefig('box plot error comparison')

#Generates the plot comparing NAN values
def nan_tracker():
    #Variable initialization. A quick check through files with lower lambda 
    #reveals that there were no NANs, so we only need to look at higher values
    #though displaying all of it for representation purposes.
    nancount = np.zeros(12)
    start = 10
    count = 0
    
    #Range of values
    lambas = np.array((8, 12, 16, 24, 32, 48, 64, 128, 256, 512, 1024, 2048))
    lambas_list = [8, 12, 16, 24, 32, 48, 64, 128, 256, 512, 1024, 2048]
    default_x_ticks = range(len(lambas_list))

    #Results file, row[1] = nan means Sinkhorn distance was nan
    with open('res2.txt') as file:
        csvreader = csv.reader(file, delimiter=',')
        for row in csvreader:
            if count < 1000:
                if row[1] == 'nan':
                    nancount[7] += 1
            elif count < 2000:
                if row[1] == 'nan':
                    nancount[8] += 1
            elif count < 3000:
                if row[1] == 'nan':
                    nancount[9] += 1
            elif count < 4000:
                if row[1] == 'nan':
                    nancount[10] += 1
            elif count < 5000:
                if row[1] == 'nan':
                    nancount[11] += 1
            count += 1
    print(nancount)

    #Generates and then saves the plot
    plt.plot(lambas.astype('str'), nancount, marker='.')
    plt.xlabel('λ value')
    plt.ylabel('NANs per 1000 trials')
    plt.title('NANs of Sinkhorn distances for varying λ')
    plt.ylim(-20, 500)
    plt.grid()
    plt.savefig('nans')

if __name__ == '__main__':
    print('main function called')
    accuracy_compare_results()