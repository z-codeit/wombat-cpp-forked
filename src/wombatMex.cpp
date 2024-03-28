#include "mex.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "matrix.h"
#include <cstring>

using namespace std;

void runWombat(double *gridB, double targetScore, double timeLimit, double weight, double& score, mxArray*& heatmap, mxArray*& solutionGrid) {
    // Simulating Wombat behavior with print statements

    // Declare and Initialize output variables
    score = 181;

    const mwSize rowNum = 13;
    const mwSize colNum = 13;
    heatmap = mxCreateNumericMatrix(rowNum, colNum, mxDOUBLE_CLASS, mxREAL);
    
    const mwSize rowChar = 13;
    const mwSize colChar = 1; // 1 column for cell array
    solutionGrid = mxCreateCellMatrix(rowChar, colChar); // Create a cell array

    //this is not working
    
    //mwSize numDimensions = 2;
    //const mwSize dimensions[] = {13, 13};
    //solutionGrid = mxCreateCharArray(numDimensions, dimensions); 
    
    double *heatmapData = mxGetPr(heatmap);
    char* solutionData = mxArrayToString(solutionGrid);
    //cout << "score: " << score << endl;

    // Populate heatmap
    for (int i = 0; i < 13 * 13; ++i) {
        heatmapData[i] = i%2;
    }

     //Populate solution grid with dummy data 
    //int letterCount = 0;
    const char *solutionStrings[] = {"STOG@PRECIADO","TANAKA@DANLAD", "@RAYA@PEREIRA", "MENA@HARIT@NJ", "AMA@MARS@EI@D", "EI@WASTON@FAI", "D@LARSEN@FATI", "AMARTEY@VU@K@", "@ORDIN@GARCIA", "ARI@N@MERTENS", "BENZEMA@E@ASA", "DN@EZ@NELSSON", "IOVA@DEPAY@NO"};
    for (int i = 0; i < 13; i++) {
        mxArray *str = mxCreateString(solutionStrings[i]);
        mxSetCell(solutionGrid, i, str);
    }
    //for (int i = 0; i < 13; i++) {
    //    const char *str = solutionStrings[i];
    //    for (int j = 0; str[j] != '\0'; j++) {
    //        solutionData[letterCount] = str[j];
    //        letterCount++;
    //    }
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {

    // Check input and output arguments
    if ((nrhs != 6) || (nlhs != 3))
        mexErrMsgIdAndTxt("Invalid Arguments","Should be called as [score, heatmap, solutionGrid] = wombatMex(GridB, targetScore, timeLimit, weight, dictR, dictT)");
   
    // Get input arguments
    double *gridB = mxGetPr(prhs[0]);
    double targetScore = mxGetScalar(prhs[1]);
    double timeLimit = mxGetScalar(prhs[2]);
    double weight = mxGetScalar(prhs[4]);
    Dictionary regDictionary = ;
    Dictionary themDictionary = ;

    // Output variables
    mxArray *scoreArray = mxCreateDoubleMatrix(1, 1, mxREAL);
    double *score = mxGetPr(scoreArray);

    mxArray *heatmap;
    mxArray *solutionGrid;

    // Run Wombat (dummy simulation)
    runWombat(gridB, targetScore, timeLimit, weight, *score, heatmap, solutionGrid);

    // Assign outputs
    plhs[0] = scoreArray;
    plhs[1] = heatmap;
    plhs[2] = solutionGrid;
}
