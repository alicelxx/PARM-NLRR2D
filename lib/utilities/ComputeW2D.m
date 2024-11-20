function W_Img = ComputeW2D(NL_mat,Height,Width,Par,NeighborInfo)
% -----------------------------------------------------------------------
%  W_Img = ComputeW2D(NL_mat,Height,Width,Par,NeighborInfo)
%  Computes the weighted count matrix
% -----------------------------------------------------------------------
J   =  size(NL_mat,2);       
Dim = Par.patsize*Par.patsize;
TotalPatNum = (NeighborInfo.NeighborH_end-NeighborInfo.NeighborH_start+1)...
    *(NeighborInfo.NeighborW_end-NeighborInfo.NeighborW_start+1); 
W   =  zeros(Dim,TotalPatNum);                               % Weighted counts for each patch

for i = 1:J
    NL_mati       =  NL_mat(1:Par.patnum,i);
    W(:,NL_mati)  =  W(:,NL_mati)+ Par.mu*ones(Dim,Par.patnum);
end
W_Img = Patch2Im(W, Par.patsize, Height, Width, NeighborInfo);             % Weighted counts for each pixel
end