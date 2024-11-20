% Add gamma noise    
NumL = 1;
NumImg = 1;
Images = {'Monarch'};
ImageFormat = '.png';

% NumL = 1;
% NumImg = 1;
% Images = {'Remote2'};
% ImageFormat = '.jpg';

shiftgivendata = 0;

for L = [1 3 5]
    for j = 1:NumImg
        ImageName = Images{j};
        O_Img = double(imread(strcat(ImageName,ImageFormat)));
        s = zeros(size(O_Img));
        for k = 1:L
            s = s + abs(randn(size(O_Img)) + 1i * randn(size(O_Img))).^2 / 2;
        end
        Bn = O_Img.*(s/L);
        N_Img = Bn + shiftgivendata;
        imwrite(uint8(N_Img),strcat(ImageName,'_',num2str(L),'.png'))
        save(strcat(ImageName,'_',num2str(L),'.mat'),'N_Img')
        clear s Bn N_Img
        clear O_Img
    end
end
