function z_hat = Prox_Exp_Speckle(u,f,lambda,alpha,beta,initial,err_tol)
% -----------------------------------------------------------------------
%  z_hat = Prox_Exp_Speckle(u,f,lambda,alpha,beta,initial,err_tol)
%  z_hat = arg min_z {1/lambda(<z+f/e^z,1>_W +
%  alpha||sqrt(e^z/f)-beta 1||_W^2 + 1/2||u-z||_W^2)}
%  Computes the proximity operator at u
% -----------------------------------------------------------------------

[m,n] = size(u);
z_hat = initial;
i = 0;
err = 1;

while (err > err_tol && i<= 20)
    ratio_e_f = exp(z_hat)./f;
    F = ones(m,n) - 1./ratio_e_f + alpha*(ratio_e_f-beta.*sqrt(ratio_e_f))...
        + (z_hat-u)*lambda;
    H = 1./ratio_e_f + alpha*(ratio_e_f-beta./2*sqrt(ratio_e_f))...
        + ones(m,n)*lambda;
    ratio_F_H = F./H;
    z_hat = z_hat - ratio_F_H;
    err = max(max(abs(ratio_F_H)));
    i=i+1;
end
end