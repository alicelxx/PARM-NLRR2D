currentFolder = pwd;
addpath(genpath(currentFolder))

TestData = {'Monarch'};
NoiseLevel = {1 3 5};

if isempty(gcp('nocreate'))
    MyPool = parpool('local');
end

for DataID = 1:length(TestData)
    DataName =  TestData{DataID};
    for NoiseID = 3%1:length(NoiseLevel)
        L        =  NoiseLevel{NoiseID};

        %--------------- Load Data ---------------
        disp( ['========== Experiment on ' DataName ' ==========']);
        LoadRoad =  ['TestImg/' DataName];
        O_Img    =  double(imread([LoadRoad '.png']));
        load([LoadRoad '_' num2str(L) '.mat']); 

        %--------------- Set Parameters ---------------
        Par   = ParSet2D(L); 
        fprintf( 'Parameteres : L = %1.0f, alpha = %2.2f \n', L, Par.alpha); 

        %--------------- Denoising ---------------
        % [E_Img, E_Ave] = PARM_Denoising2D(N_Img, Par);               % No hybrid programing
        % [E_Img, E_Ave] = PARM_Denoising2D_C(N_Img, Par, Initial);    
        [E_Img, E_Ave] = PARM_Denoising2D_C(N_Img, Par);               % Hybrid programming with language C
        
        %--------------- Display Outcomes ---------------
        ShowComparison2D(O_Img,N_Img,E_Img,E_Ave);
        
        %--------------- Save Data ---------------
        SaveRoad =  ['Results/' DataName '_' num2str(L)];
        mkdir(SaveRoad);
        save([SaveRoad '/' DataName '_' num2str(L) '_PARM_' num2str(Par.alpha) '.mat'],'E_Img','E_Ave')
    end
end

% delete(gcp('nocreate'))
return;



function Par = ParSet2D(L)
% -----------------------------------------------------------------------
%  Par = ParSet2D(L)
%  Sets the parameters
% -----------------------------------------------------------------------
Par.L         =   L;
Par.SearchWin =   50;                                   % Non-local patch searching window
    
if L >= 10
    Par.patsize       =   7;
    Par.patnum        =   80;
    Par.iter          =   30; 
    Par.alpha         =   2;
    Par.beta          =   1.1;
    Par.betak         =   1.001;
    Par.tau           =   Par.betak/1000;
    Par.mu            =   1;
    Par.epsilon       =   1E-10;
    Par.lambda        =   1;
    Par.innerloop     =   2;  
    Par.errtol        =   3E-3;
    Par.K0            =   10;
elseif L >= 5
    Par.patsize       =   8;
    Par.patnum        =   100;
    Par.iter          =   40;
    Par.alpha         =   2;
    Par.beta          =   1.3;
    Par.betak         =   1.001;
    Par.tau           =   Par.betak/250;
    Par.mu            =   1;
    Par.epsilon       =   1E-10;
    Par.lambda        =   0.6;
    Par.innerloop     =   2;
    Par.errtol        =   3E-3;
    Par.K0            =   17;
elseif L >= 3
    Par.patsize       =   9;
    Par.patnum        =   120;
    Par.iter          =   100;
    Par.alpha         =   1.5;
    Par.beta          =   1.9;
    Par.betak         =   1.001;
    Par.tau           =   Par.betak/150;
    Par.mu            =   1;
    Par.epsilon       =   1E-10;
    Par.lambda        =   1;
    Par.innerloop     =   2;
    Par.errtol        =   3E-3;
    Par.K0            =   25;
elseif L>=1
    Par.patsize       =   10;
    Par.patnum        =   150;
    Par.iter          =   200;
    Par.alpha         =   0.01;
    Par.beta          =   4;
    Par.betak         =   1.001;
    Par.tau           =   Par.betak/50;
    Par.mu            =   1;
    Par.epsilon       =   1E-10;
    Par.lambda        =   1.8; 
    Par.innerloop     =   2;
    Par.errtol        =   2E-3;
    Par.K0            =   100;
else
    disp('Error! Wrong parameter settings!')
end

Par.step      =  floor((Par.patsize)/2-1);   % the step between each keypatch
end
