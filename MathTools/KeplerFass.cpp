//
//  KeplerFass.cpp
//  MathTools
//
//  Created by Maximilian Scheurer on 26.02.14.
//  Copyright (c) 2014 Peter Rodenkirch. All rights reserved.
//

#include "KeplerFass.h"
#include "math.h"
using namespace std;
double functionValue(double);
double numericIntegral(double a, double b);
void KeplerFass::startAriaCalculation(){
    cout << "Enter 1234 as limit B to stop \n";
    while (true) {
        int a = 0, b =0;
        cout << "A:";
        cin >> a;
        cout << "B:";
        cin >> b;
        if (b == 1234) {
            break;
        }
        cout << "Aria: " << numericIntegral(a, b) <<"\n";
    }
}

double functionValue(double x) {
    double result;
    result = pow(x, 2);
    //cout << "Function value: " << result <<"\n";
    return result;
}

double numericIntegral(double a, double b) {
    double aria;
    aria = ((b-a)/6.0) * (functionValue(a) + 4.0*functionValue((a+b)/2.0)+ functionValue(b));
    return aria;
}