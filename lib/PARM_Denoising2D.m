function [E_Img, E_Ave]   =  PARM_Denoising2D( N_Img, Par, Initial )
% -----------------------------------------------------------------------
%  [X_Img,X_Ave] = PARM_Denoising2D(N_Img, Par, Initial)
%  Removes multiplicative noise by PARM
% -----------------------------------------------------------------------

N_Img = max(N_Img,1E-8);

if nargin <3
    X_Img = log(N_Img);
elseif size(Initial) == size(N_Img)
    X_Img = log(max(Initial,1E-8));
else 
    disp('Error! Wrong initialization!')
    return;
end

if size(X_Img,3)>1
    disp('Error! Wrong image size!')
    return;
end

% Initialization
[Height,Width]  =  size(X_Img);   
W_Img           =  zeros(Height, Width, 'double');                          % Weighted counts
Dim             =  Par.patsize * Par.patsize;                               % Patch dimension
Patnum          =  Par.patnum;
Patsize         =  Par.patsize;
X_Img_old       =  X_Img; 
normN           =  norm(X_Img(:));

[Neighbor_arr, Num_arr, Self_arr, NeighborInfo] = NeighborIndex2D(Height, Width, Par);
J              =  NeighborInfo.R_GridH*NeighborInfo.C_GridW;  
NL_mat         =  zeros(Patnum,J,'int32');                                   % NL Patch index matrix
TotalPatNum    =  (NeighborInfo.NeighborH_end-NeighborInfo.NeighborH_start+1)*...
    (NeighborInfo.NeighborW_end-NeighborInfo.NeighborW_start+1);             % Total Patch Number
CurPat         =  zeros(Dim, TotalPatNum,'single');                          % Current patches


for iter = 1 : Par.iter 
    
        CurPat	=	Im2Patch(X_Img,Patsize,NeighborInfo);                      % Image to patch           
    

    if (mod(iter-1,Par.innerloop)==0)
        
        % Parameter
        Weights  =  zeros(min(Dim,Patnum), J);
        NL_mat   =  Block_matching(CurPat, Par.patnum, Neighbor_arr, Num_arr, Self_arr);  % Block matching
        W_Img    =  ComputeW2D(NL_mat,Height,Width,Par,NeighborInfo);  
%         sqW_Img = sqrt(Sum_W_Img);
    end
   
        [Sum_RjT_Yj_Img,Weights]  =  PatEstimation2D(NL_mat, CurPat, Weights,...
            Par, Height, Width, NeighborInfo);                                 % Estimate all the patches
    
 
    [X_Img,X_Ave]  =  XEstimation2D(X_Img, Sum_RjT_Yj_Img, W_Img, N_Img, Par); % Estimate the image

%     RelErr    =  norm(sqW_Img.*(X_Img(:)-X_Img_old(:)))/normN;               % Compute reltive errors
    RelErr    =  norm(X_Img(:)-X_Img_old(:))/normN;                            % Compute reltive errors
    fprintf('Iter = %2.0f, RelErr = %2.5f \n', iter, RelErr);    
    X_Img_old =  X_Img;
    if (RelErr <= Par.errtol && iter>Par.K0)
        break;
    end

end

E_Img = min(255,max(0,mean2(N_Img)/mean2(exp(X_Img))*exp(X_Img)));              % Correction
E_Ave = min(255,max(0,mean2(N_Img)/mean2(exp(X_Ave))*exp(X_Ave)));              % Correction

end