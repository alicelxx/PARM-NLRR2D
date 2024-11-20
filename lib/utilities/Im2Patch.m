function  Y  =  Im2Patch(E_Img, patsize,NeighborInfo)
% -----------------------------------------------------------------------
%  Y = Im2Patch(E_Img, patsize,NeighborInfo)
%  Computes current patches from the image
% -----------------------------------------------------------------------
NeighborH_start = NeighborInfo.NeighborH_start;
NeighborH_end = NeighborInfo.NeighborH_end;
NeighborW_start = NeighborInfo.NeighborW_start;
NeighborW_end = NeighborInfo.NeighborW_end;
TotalPatNum = (NeighborH_end-NeighborH_start+1)*(NeighborW_end-...
    NeighborW_start+1);                                                 %Total Patch Number in the image
Y           =   zeros(patsize*patsize, TotalPatNum, 'single');          %Current Patches
k           =   0;

for i  = 1:patsize
    for j  = 1:patsize
              k     =  k+1;
        E_patch     =  E_Img(NeighborH_start-1+i:NeighborH_end-1+i,...
                NeighborW_start-1+j:NeighborW_end-1+j);   
        Y(k,:)      =  E_patch(:)';
    end
end
