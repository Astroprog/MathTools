//
//  Term.h
//  MathTools
//
//  Created by Peter Rodenkirch on 26.02.14.
//  Copyright (c) 2014 Peter Rodenkirch. All rights reserved.
//

#ifndef __MathTools__Term__
#define __MathTools__Term__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <stack>

typedef enum TermFunction
{
    polynom,
    sinus,
    cosinus,
    tangens
} TermFunction;

typedef enum Operator
{
    none,
    addition,
    subtraction,
    multiplication,
    division
} Operator;

class Term {
    
public:
    
    TermFunction type;
    Operator previousOperator;
    Operator followingOperator;
    double power;
    std::vector<Term*> *subTerms;
    
    
    Term();
    Term(std::string input);
    static double stringToDouble(std::string& s);
    void parseInput(std::string input);
    static std::string eraseSpaces(std::string input);
    static std::string shuntingYard(std::string input);
    
};

#endif /* defined(__MathTools__Term__) */
