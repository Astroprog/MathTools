//
//  Playground.cpp
//  MathTools
//
//  Created by Peter Rodenkirch on 02.03.14.
//  Copyright (c) 2014 Peter Rodenkirch. All rights reserved.
//

#include "Playground.h"
#include "GeneralUtils.h"

using namespace std;

void Playground::haveFun()
{
    //    for (int i = 0;  i < argc; i++) {
    //        cout << argv[i] << endl;
    //    }
    
    double **array = 0;
    int columns = 3;
    int rows = 3;
    array = new double *[columns];
    for (int i = 0; i < columns; i++) {
        array[i] = new double [rows];
    }
    
    Matrix *tempMatrix = new Matrix("{{0,2,0,4},{4,5,6,7},{7,8,9,1},{1,4,7,2}}");
    Matrix *testMatrix = new Matrix();
    
    Matrix::printMatrix(tempMatrix);
    testMatrix = Matrix::zeilenStufenForm(tempMatrix);
    Matrix::printMatrix(testMatrix);
    testMatrix = Matrix::triagonal(tempMatrix);
    Matrix::printMatrix(testMatrix);
    cout << Matrix::determinante(tempMatrix) << endl;
    
    string input = "(((x - 5) * x^2) + 6) * (x + 5)";
    cout << input << endl;
    Term *temp = new Term(input);
    cout << temp->subTerms->size() << endl;
    cout << endl;
    
    vector<double>* vec1 = Matrix::makeVector("1,2,3");
    vector<double>* vec2 = Matrix::makeVector("3,1,3");
    Matrix::printVector(vec1);
    Matrix::printVector(vec2);
    vector<double>* result = Matrix::crossProduct(vec1, vec2);
    Matrix::printVector(result);
    cout << (Matrix::dotProduct(result, vec1)) << "\n";
    cout << GeneralUtils::toDegrees(Matrix::getAngle(vec1, vec2));
    KeplerFass::startAriaCalculation();
}