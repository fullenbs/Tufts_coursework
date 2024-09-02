% -------------------------------------------------------------------------
% This code implements the power method
% -------------------------------------------------------------------------
% Load data
load('stochastic_matrix.mat')
% Implement the power method
% Set tolerance and maximum number of iterations
tol = 1e-5;
maxit = 100;
n = length(B);
x = randn(n,1);
lam_init = x'*B*x/(x'*x);
error = [];
for i = 1:maxit
   x_old = x;
   z = B*x;
   x = z/norm(z);
   lam = x'*B*x;
   error = [error ; abs(4-lam)];
   if norm(x-x_old)<1e-6
       break
   end
end
% Plot covergence curve
figure
semilogy(1:i,error,'r', 'LineWidth',2)
xlabel('Iteration number = k','FontSize',15)
ylabel('$|\lambda_k-1|$','interpreter','latex','FontSize',15)
title('Covergence of power iteration')
grid on
saveas(1,'Power_method_convergence','png')