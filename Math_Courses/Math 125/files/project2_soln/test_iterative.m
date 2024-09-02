% -------------------------------------------------------------------------
% This script implements the Jacobi and Gauss-Seidel  methods to solve
% the linear system problem Ax=b in problem 2
% -------------------------------------------------------------------------
% Set up the system: the matrix A and the right hand side vector b
n = 1000;
e = ones(n,1);
A = spdiags([-e 2*e -e],-1:1,n,n);
h = 0.1;
x = 1:n;
b = h^2*sin(x*h*pi);
b = b';
% Iteration matrix for Jacobi: M_J = I - inv(D)*A
D = 2*eye(n);
M_J = eye(n) - 0.5*A;
% Check if all the eigenvalues of M_J are less than 1 in absolute value
check_eigs = find(abs(eig(M_J))>1);
if length(check_eigs)==0
   fprintf(" The spectral radius of the iteration matrix is less than %1d\n",1) 
end
% Compare Jacobi and Gauss-Seidel 
tol = 1e-4;
x = zeros(n,1);
[x_jacobi,error_jacobi] = jacobi(A,b,tol);
[x_gauss,error_gauss] = gauss_seidel(A,b,tol);
figure
semilogy(1:length(error_jacobi),error_jacobi,'r', 'LineWidth',2)
hold on
semilogy(1:length(error_gauss),error_gauss,'k', 'LineWidth',2)
xlabel('Iteration number = k','FontSize',15)
ylabel('$||Ax-b||$','interpreter','latex','FontSize',15)
title('Comparison of covergence of Jacobi and Gauss Seidel')
grid on
legend('Jacobi','Gauss Seidel')




