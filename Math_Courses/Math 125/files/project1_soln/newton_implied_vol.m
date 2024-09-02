% -------------------------------------------------------------------------
% This script implements Newton's method for implied volatility estimation
% -------------------------------------------------------------------------
% -------------------------------------------------------------------------
% This code implements Newton's method
% -------------------------------------------------------------------------
function root = newton_implied_vol(tol,S,K,T,t,r,C)
% Newton method 
sigma = sqrt(2*abs(log(S/K)+r*(T-t))/(T-t));
while 1
    % Call Black-Scholes and vega
    f_sigma = black_scholes(S,K,r,t,T,sigma)-C;
    d1 = (log(S/K)+(r+0.5*sigma^2)*(T-t))/(sigma*sqrt(T-t));
    f_der_sigma = S*sqrt(T-t)*normpdf(d1);
    sigma_new = sigma - (f_sigma/f_der_sigma);
    fprintf("%.8f\n",sigma) 
    if abs(sigma_new-sigma)<tol 
        break
    end
    sigma = sigma_new;
end
root= sigma;
end