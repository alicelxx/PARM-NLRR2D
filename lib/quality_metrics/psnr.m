function s=psnr(A,B)

s=10*log10(255^2/(mean((A(:)-B(:)).^2)));

return;