function ShowComparison2D(O_Img,N_Img,E_Img,E_Ave)
%% Use to show the video result of TC methods

figure
subplot(2,2,1);
imshow(uint8(O_Img));
title('Original Image');

PSNR  =  psnr(O_Img, N_Img);
SSIM  =  ssim_index(O_Img, N_Img);
subplot(2,2,2);
imshow(uint8(N_Img));
title(['Noisy Image : (' num2str(PSNR,'%2.2f') ' dB, ' num2str(SSIM,'%2.4f') ')']);
disp(['Noisy Image :     (' num2str(PSNR,'%2.2f') ' dB, ' num2str(SSIM,'%2.4f') ')']);

PSNR  =  psnr(O_Img, E_Img);
SSIM  =  ssim_index(O_Img, E_Img);
subplot(2,2,3);
imshow(uint8(E_Img));
title(['Est. Image : (' num2str(PSNR,'%2.2f') ' dB, ' num2str(SSIM,'%2.4f') ')']);
disp(['Est. Image :      (' num2str(PSNR,'%2.2f') ' dB, ' num2str(SSIM,'%2.4f') ')']);

PSNR  =  psnr(O_Img, E_Ave);
SSIM  =  ssim_index(O_Img, E_Ave);
subplot(2,2,4);
imshow(uint8(E_Ave));
title(['Est. Ave. Image : (' num2str(PSNR,'%2.2f') ' dB, ' num2str(SSIM,'%2.4f') ')']);
disp(['Est. Ave. Image : (' num2str(PSNR,'%2.2f') ' dB, ' num2str(SSIM,'%2.4f') ')']);

end