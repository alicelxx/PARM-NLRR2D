function  [X_Img,X_Ave]  =  XEstimation2D(Xk, Sum_RjT_Yj_Img, W_Img, N_Img, Par)
% -----------------------------------------------------------------------
%  [X_Img,X_Ave]  =  XEstimation2D(Xk, Sum_RjT_Yj_Img, W_Img, N_Img, Par)
%  Estimates the images
% -----------------------------------------------------------------------

X_Ave  =  Sum_RjT_Yj_Img./(W_Img+eps);
u      =  (1-1/Par.betak)*Xk + 1/Par.betak*X_Ave;
X_Img  =  Prox_Exp_Speckle(u,N_Img,Par.betak/Par.tau,Par.alpha,Par.beta,Xk,1E-8);
end
