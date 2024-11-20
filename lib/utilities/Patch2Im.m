function  E_Img  =  Patch2Im(ImPat,PatSize, ImageH, ImageW, NeighborInfo)
% -----------------------------------------------------------------------
%  E_Img  =  Patch2Im(ImPat,PatSize, ImageH, ImageW, NeighborInfo)
%  Computes the image from current patches
% -----------------------------------------------------------------------
TempR        =   NeighborInfo.NeighborH_end-NeighborInfo.NeighborH_start+1;
TempC        =   NeighborInfo.NeighborW_end-NeighborInfo.NeighborW_start+1;
TempOffsetR  =   NeighborInfo.NeighborH_start:NeighborInfo.NeighborH_end;
TempOffsetC  =   NeighborInfo.NeighborW_start:NeighborInfo.NeighborW_end;

E_Img  	=  zeros(ImageH,ImageW);
k        =   0;
for i  = 1:PatSize
    for j  = 1:PatSize
        k    =  k+1;
        E_Img(TempOffsetR-1+i,TempOffsetC-1+j)  =  E_Img(TempOffsetR-1+i,...
            TempOffsetC-1+j) + reshape( ImPat(k,:)', [TempR TempC]);
    end
 end
 end

