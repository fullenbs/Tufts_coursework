% -------------------------------------------------------------------------
% This script does spline interpolation on the spline_data.mat
% -------------------------------------------------------------------------
load('spline_data.mat');
% Form A
% Not optimized for efficiency
A= zeros(59,59);
A(1,1)=2;
A(1,2)=1;
A(59,58)=1;
A(59,59)=2;
for i = 2:58
   A(i,i)=4;
   A(i,i-1)=1;
   A(i,i+1)=1;
end
% Data y
y = data(:,2);
% z is the RHS vector to the linear system
z = zeros(59,1);
z(1) = 3*(y(2)-y(1));
z(59)= 3*(y(59)-y(58));
for i = 2:58
    z(i) = 3*(y(i+1)-y(i-1));
end
% Solve
D = A\z;
% Solve a_i,b_i, c_i and d_i
coeff= zeros(59,4);
for i = 1:58
coeff(i,1) = y(i);
coeff(i,2) = D(i);
coeff(i,3)  = 3*(y(i+1)-y(i))-2*D(i)-D(i+1);
coeff(i,4) = 2*(y(i)-y(i+1))+D(i) + D(i+1);
end
t = data(:,1);
scatter(data(:,1),data(:,2),20,'b*')
% Plot each cubic polynomial
% Note: we need to transform back to the t-variable from the u-variable
for i = 1:58
    if t(i)<t(i+1)
        t_int = t(i):0.00001:t(i+1);
    else
        t_int = t(i):-0.00001:t(i+1);
    end
    tt1= (t_int-t(i));
    tt2 =(t(i+1)-t(i));
    scatter(t_int,coeff(i,1)+ coeff(i,2).* tt1/tt2 + coeff(i,3).* tt1.^2/tt2^2+coeff(i,4).* tt1.^3/tt2^3,'r');
    hold on
end


