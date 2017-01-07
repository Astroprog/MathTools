//
//  GeneralUtils.cpp
//  MathTools
//
//  Created by Maximilian Scheurer on 02.03.14.
//  Copyright (c) 2014 Peter Rodenkirch. All rights reserved.
//

#include "GeneralUtils.h"
#include "math.h"
using namespace std;

double GeneralUtils::toDegrees(double angle){
    double result = 0.0;
    result = angle/(M_PI * 2) * 360;
    return result;
    
}

double GeneralUtils::toRadian(double angle){
    double result = 0.0;
    result = M_PI * 2 * (angle/360);
    return result;
}