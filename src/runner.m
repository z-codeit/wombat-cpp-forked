
%gridB (:,:,:) logical
%  targetScore (1,1) double
%   timeLimit (1,1) double
%   jobID (1,:) char
%   weight (1,1) double
%    year (1,1) double
%    gridC (:,:,:) char = []
%   parallel (:,:) logical = false %#ok<INUSA>



% Sample MATLAB script to run the MEX function

% Define input parameters
gridB = rand(13, 26); % Example grid, adjust dimensions as needed
targetScore = 200;
timeLimit = 100;
weight = 0.5;
thematicDictionary = {'word1', 'word2', 'word3'}; % Example thematic dictionary
regularDictionary = {'word4', 'word5', 'word6'}; % Example regular dictionary

% Call the MEX function
[score, heatmap, solutionGrid] = wombatMex(gridB, targetScore, timeLimit, weight, thematicDictionary, regularDictionary);

% Display results
disp(['Score: ' num2str(score)]);
disp('Heatmap:');
disp(heatmap);
disp('Solution Grid:');
disp(solutionGrid);
