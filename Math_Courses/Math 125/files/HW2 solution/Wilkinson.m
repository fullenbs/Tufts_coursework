% -------------------------------------------------------------------------
% This code considers the conditioning of the Wilkinson polynomial
% -------------------------------------------------------------------------
% The polynomial coefficients of the Wilkinson polynomial. x^20-210x^19+20615x^18+....
coeff = [1; -210; 20615; -1256850; 53327946; -1672280820; 40171771630;   -756111184500; 11310276995381; -135585182899530; 1307535010540395;
  -10142299865511450; 63030812099294896; -311333643161390640;   1206647803780373360; -3599979517947607200; 8037811822645051776;
  -12870931245150988800; 13803759753640704000; -8752948036761600000; 2432902008176640000];
% Exact roots
exact_roots = [20:-1:1]';
% Numerically computed roots after pertubation of the coefficient of x^19  by -2^{-23}
coeff(2) = coeff(2)-2^-23;
perturbed_roots = roots(coeff);
% Compute approximate relative condition number
rel_error = abs(perturbed_roots-exact_roots)./(abs(exact_roots));