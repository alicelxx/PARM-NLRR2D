function  [X, w] =  WNNM( Y, lambdai, w, epsilon)
% -----------------------------------------------------------------------
%  [X, w] =  WNNM( Y, lambdai, w, epsilon)
%  Computes the weighted nuclear norm minimization with weights w
% -----------------------------------------------------------------------
[U,SigmaY,V] =   svd(double(Y),'econ'); 
if (w(1) == 0)
    w = 1./(diag(SigmaY)+epsilon);
end        
SigmaX =  max(diag(SigmaY)-lambdai*w,0);
ind    =  find (SigmaX>0);
svp    =  length(ind);
w      =  [1./(SigmaX(ind)+epsilon); 1./epsilon*ones(size(w,1)-svp,1)];
X      =  single( U(:,1:svp)*diag(SigmaX(ind))*V(:,1:svp)');
end

