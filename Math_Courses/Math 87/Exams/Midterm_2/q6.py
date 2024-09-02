import json
import numpy as np
float_formatter = "{:.5f}".format
np.set_printoptions(formatter={'float_kind':float_formatter})

def bv(it,items):
    return np.array([1.0 if i == items.index(it)else 0.0 for i in range(len(items))])
## >>> bv("c",["a","b","c","d"])
## array([0.00000, 0.00000, 1.00000, 0.00000])
def adj_from_json(json_file):
    with open(json_file) as f:
        adj_data = json.load(f)
    dict = {}
    for i in adj_data:
        lfrom = i['from']
        lto = i['to']
        if lfrom in dict.keys():
            dict[lfrom].add(lto)
        else:
            dict[lfrom] = set()
            dict[lfrom].add(lto)
        if not(lto in dict.keys()):
            dict[lto] = set()
    sites = list(dict.keys())
    A = np.array([sum([bv(l_to,sites) for l_to in dict[l_from]],
    np.zeros(len(sites)))
    for l_from in sites])
    return (sites, A)

def make_transition(A,p):
    (n,m) = A.shape
    T = np.zeros((n, n))

    for i in range(0, n): #creates transition matrix
        ones_count = 0
        for j in range(0, n): #finds number of ones in a column
            if A[j, i] == 1:
                ones_count = ones_count + 1
        if ones_count == 0: #if no ones, replace the column with 1/n
            T[:,i] = np.ones((1, n))/n
        else:
            T[:,i] = np.copy(A[:,i]/ones_count) 
    ones_mat = np.ones((n, n))*p/n
    return (1-p)*T + ones_mat #complete equation


(list, C) = adj_from_json("data.json")
D = make_transition(C, p=0.70)
#print(D)
e_val, e_vec = np.linalg.eig(D)
v = e_vec[:,0]
w = (1/sum(v,0))*v
#ind = np.argpartition(w, -10)[-10:]
ind = np.argsort(w)[::-1][:10]
for i in ind:
    print(w[i], list[i])

print("BREAK\n")
D = np.linalg.matrix_power(D, 93)
w_power = D[:,0]
#print(w_power)
ind = np.argsort(w)[::-1][:10]
for i in ind:
    print(w[i], list[i])



