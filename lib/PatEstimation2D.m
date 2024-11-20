function [RjT_Yj_Img, Weights] = PatEstimation2D( NL_mat, CurPat, Weights, Par, Height, Width, NeighborInfo)
% -----------------------------------------------------------------------
%  [ RjT_Yj_Img, Weights ] = PatEstimation2D( NL_mat, CurPat, Weights, Par, Height, Width, NeighborInfo)
%  Estimates all the patch matrices Y_j and computes the sum of R_j^T(Y_j^{k+1})
% -----------------------------------------------------------------------

EPat    =  zeros(size(CurPat));
C_GridW = NeighborInfo.C_GridW;
R_GridH = NeighborInfo.R_GridH;

for j = 1 : C_GridW
    Offset2_start = (j - 1)*R_GridH;
    for  i      =  1 : R_GridH                                 % For each keypatch group
        NL_mati = NL_mat(1:Par.patnum,Offset2_start+i);
        Temp    =   CurPat(:, NL_mati);
        weight  =   Weights(:,Offset2_start+i);
        [E_Temp, E_weight] = WNNM(Temp,Par.lambda/Par.mu,weight,Par.epsilon);
        Weights(:,Offset2_start+i) = E_weight;
        EPat(:,NL_mati)  = EPat(:,NL_mati)+Par.mu*E_Temp;
    end
end

RjT_Yj_Img  =  Patch2Im(EPat, Par.patsize, Height, Width, NeighborInfo); 

end
    
    

