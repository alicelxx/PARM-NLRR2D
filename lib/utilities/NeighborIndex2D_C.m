function [NeighborH,NeighborW,NumH,NumW,SelfH,SelfW,NeighborInfo]...
    =  NeighborIndex2D_C(sizeim,par,GroupId,GroupH,GroupW)
% -----------------------------------------------------------------------
%  [NeighborH,NeighborW,NumH,NumW,SelfH,SelfW,NeighborInfo]...
%  =  NeighborIndex2D_C(sizeim,par,GroupId,GroupH,GroupW)
% Computes the neighborhood indices and information
% -----------------------------------------------------------------------
SW      	=   par.SearchWin;
s           =   par.step;

TempR       =   sizeim(1)-par.patsize+1;
R_GridIdx	=   [1:s:TempR];
R_GridIdx	=   [R_GridIdx R_GridIdx(end)+1:TempR];
IdxR        =   (1:TempR);
R_GridH     =   length(R_GridIdx);   

GroupHId     =   mod(GroupId-1,GroupH)+1;  
GroupHSize_t =   ceil(R_GridH / GroupH);
GroupH_start =   GroupHSize_t * (GroupHId -1)+1;
GroupH_end   =   min(GroupHSize_t * GroupHId,R_GridH);
GroupHSize   =   GroupH_end - GroupH_start+1;

NeighborH    =   int32(zeros(2*SW+1,GroupHSize));
NumH         =   int32(zeros(1,GroupHSize));
SelfH        =   int32(zeros(1,GroupHSize));


for i = GroupH_start : GroupH_end
    OffsetR     =   R_GridIdx(i);
    top         =   max( OffsetR-SW, 1 );
    if  i== GroupH_start
        NeighborH_start = IdxR(top);
    end
    button      =   min( OffsetR+SW, TempR );
    if  i== GroupH_end
        NeighborH_end = IdxR(button);
    end
    NL_Idx     =   IdxR(top:button);
    NumH(i-GroupH_start+1)  =  length(NL_Idx); 
    NeighborH(1: length(NL_Idx),i-GroupH_start+1)  =  NL_Idx-NeighborH_start+1;   
    SelfH(i-GroupH_start+1) = OffsetR-NeighborH_start+1;
end


TempR       =   NeighborH_end-NeighborH_start+1;
TempC       =   sizeim(2)-par.patsize+1;
C_GridIdx	=   [1:s:TempC];
C_GridIdx	=   [C_GridIdx C_GridIdx(end)+1:TempC];
IdxC        =   (1:TempR*TempC);
IdxC        =   reshape(IdxC, TempR, TempC);
IdxCC       =   (1:TempC);
C_GridW     =   length(C_GridIdx);

GroupWId     =   ceil(GroupId/GroupH);
GroupWSize_t =   ceil(C_GridW / GroupW);
GroupW_start =   GroupWSize_t * (GroupWId -1)+1;
GroupW_end   =   min(GroupWSize_t * GroupWId,C_GridW);
GroupWSize   =   GroupW_end - GroupW_start+1;

NeighborW    =   int32(zeros(2*SW+1,GroupWSize));
NumW         =   int32(zeros(1,GroupWSize));
SelfW        =   int32(zeros(1,GroupWSize));

for j = GroupW_start : GroupW_end
    OffsetC = C_GridIdx(j);
    left        =   max( OffsetC-SW, 1 );
    if  j == GroupW_start
        NeighborW_start = IdxCC(left);
        NNW_start = IdxC(1,left);
    end
    right       =   min( OffsetC+SW, TempC );
    if  j == GroupW_end
        NeighborW_end = IdxCC(right);
    end
    OffsetC_start = (OffsetC-1)*TempR;
    NL_Idx     =   IdxC(1,left:right)-1;
    NL_Idx     =   NL_Idx(:);
    NumW(j-GroupW_start+1)  =  length(NL_Idx); 
    NeighborW(1: length(NL_Idx),j-GroupW_start+1)  =  NL_Idx-NNW_start+1;   
    SelfW(j-GroupW_start+1) = OffsetC_start-NNW_start+1;
end

NeighborInfo.NeighborH_start =  NeighborH_start;
NeighborInfo.NeighborH_end   =  NeighborH_end;
NeighborInfo.NeighborW_start =  NeighborW_start;
NeighborInfo.NeighborW_end   =  NeighborW_end;
NeighborInfo.R_GridH         =  GroupHSize;
NeighborInfo.C_GridW         =  GroupWSize;


end