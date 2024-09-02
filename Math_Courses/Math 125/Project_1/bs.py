import numpy as np
import math
import scipy.stats as stats

eprice = np.array([5125, 5225, 5325, 5425, 5525, 5625, 5725, 5825])
oprice = np.array([475, 405, 340, 280.5, 226, 179.5, 139, 105])
init_asset = 5420.3

#Handles all Black Scholes math, same as equations except T-t is T here
d1 = lambda S, K, r, sig, T: (np.log(S/K) + (r+0.5*sig**2)*(T))/(sig*math.sqrt(T))
d2 = lambda S, K, r, sig, T: d1(S, K, r, sig, T) - sig*np.sqrt(T)
BS_1 = lambda S, K, r, sig, T: S*stats.norm.cdf(d1(S, K, r, sig, T))
BS_2 = lambda S, K, r, sig, T: K*np.exp(-1*r*(T))*stats.norm.cdf(d2(S, K, r, sig, T))
BS = lambda S, K, r, sig, T: BS_1(S, K, r, sig, T) - BS_2(S, K, r, sig, T)
vega = lambda S, K, r, sig, T: S*np.sqrt(T)*stats.norm.pdf(d1(S, K, r, sig, T))

#Performs Newton's Method on Black-Scholes
def newt(init, eprice, oprice, r, dur,tol):
    vol_old = 0.64
    vol_new = 0
    for i in range(0, 100):
        temp = BS(init, eprice, r, vol_old, dur)-oprice
        vol_new = vol_old - temp/vega(init, eprice, r, vol_old, dur)
        if (abs(vol_new-vol_old) < tol):
            break
        vol_old = vol_new
    return vol_old

vols = np.zeros(8)
for i in range(0, len(vols)):
    vols[i] = newt(init_asset, eprice[i], oprice[i], 0.04, 4/12, tol=10**-6)
print(vols)
