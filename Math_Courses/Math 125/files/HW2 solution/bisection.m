% -------------------------------------------------------------------------
% This code implements bisection method
% -------------------------------------------------------------------------
function root = bisection(f,tol,a,b)
% bisection method 
while 1
%     for i = 1:5
    c = (a+b)/2;
    fprintf("%.8f\n",c); 
    if f(a)*f(c)>0
        a=c;
    else
        b=c;
    end
    if abs(a-b)<tol
        break
    end
end
root= c;
end