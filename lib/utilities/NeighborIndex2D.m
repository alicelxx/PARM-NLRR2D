function [Neighbor_arr,Num_arr,SelfIndex_arr,NeighborInfo]...
    =  NeighborIndex2D(im_size1,im_size2,par)
% -----------------------------------------------------------------------
%  [Neighbor_arr,Num_arr,SelfIndex_arr,NeighborInfo]...
% =  NeighborIndex2D(im_size1,im_size2, par)
% Computes the all the patch indexes in the Searching window
% -Neighbor_arr is the array of neighbor patch indexes for each keypatch
% -Num_arr is array of the effective neighbor patch numbers for each keypatch
% -SelfIndex_arr is the index of keypatches in the total patch index array 
% -----------------------------------------------------------------------
SW      	=   par.SearchWin;
s           =   par.step;
TempR       =   im_size1-par.patsize+1;
TempC       =   im_size2-par.patsize+1;
R_GridIdx	=   [1:s:TempR];
R_GridIdx	=   [R_GridIdx R_GridIdx(end)+1:TempR];
C_GridIdx	=   [1:s:TempC];
C_GridIdx	=   [C_GridIdx C_GridIdx(end)+1:TempC];

Idx         =   (1:TempR*TempC);
Idx         =   reshape(Idx, TempR, TempC);
R_GridH     =   length(R_GridIdx);    
C_GridW     =   length(C_GridIdx); 
Dim_Grid      =   R_GridH*C_GridW;

Neighbor_arr    =   zeros((2*SW+1)^2,Dim_Grid,'int32');
Num_arr         =   zeros(1,Dim_Grid,'int32');
SelfIndex_arr   =   zeros(1,Dim_Grid,'int32');

parfor Offset2 = 1:Dim_Grid
    i = mod(Offset2-1,R_GridH)+1;
    j = ceil(Offset2/R_GridH);
    OffsetR     =   R_GridIdx(i);
    OffsetC     =   C_GridIdx(j);
    Offset1  	=  (OffsetC-1)*TempR + OffsetR;

    top         =   max( OffsetR-SW, 1 );
    button      =   min( OffsetR+SW, TempR ); 
    left        =   max( OffsetC-SW, 1 );
    right       =   min( OffsetC+SW, TempC );    
    
    NL_Idx     =   Idx(top:button, left:right);
    NL_Idx     =   NL_Idx(:);
    
    Num_arr(Offset2)        =  length(NL_Idx);
    Neighbor_arr(:,Offset2) =  [NL_Idx;zeros((2*SW+1)^2-length(NL_Idx),1)];   
    SelfIndex_arr(Offset2)  =  Offset1;
    
end

NeighborInfo.NeighborH_start =  1;
NeighborInfo.NeighborH_end   =  TempR;
NeighborInfo.NeighborW_start =  1;
NeighborInfo.NeighborW_end   =  TempC;
NeighborInfo.R_GridH         =  R_GridH;
NeighborInfo.C_GridW         =  C_GridW;

end