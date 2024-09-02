% -------------------------------------------------------------------------
% This script calculates implied volatility using Newton's meethod
% -------------------------------------------------------------------------
% Parameters of the option
S = 5420.3; 
r = 0.05;
t = 0;
T = 1/3.0;
% Exercise and option price
K = 5825;
C = 105;
% Tolerance
tol = 1e-5;
% Call algorithm
sigma = newton_implied_vol(tol,S,K,T,t,r,C)
