function  [Init_Index]  =  Block_matching(X,patnum,Neighbor_arr,Num_arr,SelfIndex_arr)
% -----------------------------------------------------------------------
%  [Init_Index]  =  Block_matching(X,patnum,Neighbor_arr,Num_arr,SelfIndex_arr)
%  Computes the patch index for each nonlocal similar patch group based on
%  Euclidean distance
% -----------------------------------------------------------------------
J            =  length(Num_arr);
Init_Index   =  zeros(patnum,J,'int32');

parfor  i  =  1 : J
    Patch = X(:,SelfIndex_arr(i));
    Neighbors = X(:,Neighbor_arr(1:Num_arr(i),i));    
    Dist = sum((repmat(Patch,1,size(Neighbors,2))-Neighbors).^2);    
    [~,index] = sort(Dist); 
    Init_Index(:,i)=Neighbor_arr(index(1:patnum),i);
end