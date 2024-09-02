% -------------------------------------------------------------------------
% This code implements the price of a option using Black-Scholes formula
% -------------------------------------------------------------------------
function price = black_scholes(S,K,r,t,T,sigma)
% define d_1 and d_2
d1 = (log(S/K)+(r+0.5*sigma^2)*(T-t))/(sigma*sqrt(T-t));
d2 = d1-sigma*sqrt(T-t);
% define price
price = S*normcdf(d1)-K*exp(-r*(T-t))*normcdf(d2);
end