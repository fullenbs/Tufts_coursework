% -------------------------------------------------------------------------
% This solves the first problem of project 1
% -------------------------------------------------------------------------
theta = [0:30:330]';
declination = [408 89  -66  10  338  807  1238  1511  1583  1462  1183  804 ]'; 
% Part a: Form A, y and x such that A'*A*x = A'*y
% Note k = 1
n = length(theta);
one_vec = ones(n,1);
A = [one_vec cos(2*pi*theta/360) sin(2*pi*theta/360)];
y  = declination;
x = (A'*A)\(A'*y);
figure
scatter(theta, declination,'r*')
hold on
theta_plot = [0:1:330]';
B = [ones(length(theta_plot),1) cos(2*pi*theta_plot/360) sin(2*pi*theta_plot/360)];
plot(theta_plot,B*x,'b')
grid on
legend('Exact data', 'Least squares fit, k=1','Location','northwest')
% -------------------------------------------------------------------------
% Part b: Form A, y and x such that A'*A*x = A'*y
% Note k = 2
A = [one_vec cos(2*pi*theta/360) sin(2*pi*theta/360) cos(4*pi*theta/360) sin(4*pi*theta/360)];
y  = declination;
x = (A'*A)\(A'*y);
figure
scatter(theta, declination,'r*')
hold on
theta_p = [0:1:330]';
B = [ones(length(theta_p),1) cos(2*pi*theta_p/360) sin(2*pi*theta_p/360) ...
    cos(4*pi*theta_p/360) sin(4*pi*theta_p/360)];
plot(theta_plot,B*x,'b')
grid on
legend('Exact data', 'Least squares fit, k=2','Location','northwest')
% -------------------------------------------------------------------------
% Part c: Form A, y and x such that A'*A*x = A'*y
% Note k = 12
% Form A by iteration
A = zeros(12,12);
A(:,1)= one_vec;
for i = 1:5
   A(:,2*i:2*i+1) =[cos(2*i*pi*theta/360) sin(2*i*pi*theta/360)];
end
A(:,12)= cos(12*pi*theta/360) ;
y  = declination;
x = (A)\(y);
figure
scatter(theta, declination,'r*')
hold on
theta_p = [0:1:330]';
B = zeros(length(theta_p),12);
B(:,1)=ones(length(theta_p),1);
for i = 1:5
   B(:,2*i:2*i+1) =[cos(2*i*pi*theta_p/360) sin(2*i*pi*theta_p/360)];
end
B(:,12)= cos(12*pi*theta_p/360) ;
plot(theta_p,B*x,'b')
grid on
legend('Exact data', 'Interpolation','Location','northwest')
