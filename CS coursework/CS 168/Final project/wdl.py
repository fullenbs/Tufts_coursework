#This won't run, which is intentional, go to the README
if __name__ == '__main__':      
    #Assume you have access to this
    C = torch.load('Cost_matrix.pt')
    data = torch.load('data.pt')

    plt.plot(data)
    plt.title('Normalized hyperspectral image pixels')
    plt.savefig('Initial data')
    plt.clf()

    #Does WDL stuff
    barySolver = barycenter(C=C, reg=0.02)
    weights, DLearned = wdl.fit(data, C=C, reg=0.02)

    #Plots
    plt.plot(DLearned)
    plt.title('All atoms, num=2')
    plt.savefig('All_atoms')
    plt.clf()

    #Makes more plots
    b = np.zeros((201, 201))
    for i in range(0, 201):
        b[i,:] = barySolver(weights[i,:], DLearned)
    plt.plot(b)
    plt.show()
    plt.title('Normalized  hyperspectral image pixels')
    plt.savefig('reconstruction')
