Proximal Alternating Reweighted Minimization for Multiplicative Noise Removal, Version 2.0
%
% Please refer to the following our paper:
%
% Xiaoxia Liu, Jian Lu, Lixin Shen, Chen Xu, and Yuesheng Xu, 
% "Multiplicative noise removal: Nonlocal low-rank model 
% and its proximal alternating reweighted minimization
% algorithm," SIAM J. Imag. Sci., vol. 13, no. 3, pp. 1595–1629, 2020.
% 
% ----------------------------------------------------------------------
% Permission to use, copy, or modify this software and its documentation
% for educational and research purposes only and without fee is here
% granted, provided that this copyright notice and the original authors'
% names appear on all copies and supporting documentation. This program
% shall not be used, rewritten, or adapted as the basis of a commercial
% software or hardware product without first obtaining permission of the
% authors. The authors make no representations about the suitability of
% this software for any purpose. It is provided "as is" without express
% or implied warranty.
%----------------------------------------------------------------------
%
% This demo is the PARM algorithm for multiplicative noise removal. 
% The program using parallel computing is expected to run on 
% high-performance computers with multi-core processors. 
%  
% For other applications, you may modify 
% 1. the initialization and correction in PARM_Denoising;
% 2. the fidelity function in XEstimation;
% 3. the low-rank regularizer in PatEstimation.
% 
% ----------------------------------------------------------------------
% If you find any bug, please contact xiaoxia_liu_math@outlook.com.
% Nov 8, 2022
% =============================================
