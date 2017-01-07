//
//  Term.cpp
//  MathTools
//
//  Created by Peter Rodenkirch on 26.02.14.
//  Copyright (c) 2014 Peter Rodenkirch. All rights reserved.
//

#include "Term.h"

using namespace std;

double Term::stringToDouble(std::string& s)
{
    istringstream i(s);
    double x;
    if (!(i >> x))
        return 0;
    return x;
}

std::string Term::eraseSpaces(std::string input)
{
    unsigned j = 0;
    for(unsigned i = 0; i < input.size(); i++)
        if(input[i] != ' ')
            input[j++] = input[i];
    input.resize(j);
    return input;
}


void Term::parseInput(std::string input)
{
    int i = 0;
    int pos1 = 0;
    bool substringActive = false;
    int pushValue = 0;
    input = eraseSpaces(input);
    
    for (char &c : input) {
        
        if (c == '(') {
            if (!substringActive) {
                substringActive = true;
                pos1 = i + 1;
            }
            pushValue++;
        } else if(c == ')') {
            if (!substringActive) {
                cout << "Syntax error" << endl;
            } else {
                if (pushValue == 1) {
                    substringActive = false;
                    string substring = input.substr(pos1, i - pos1);
                    cout << "Substring: " << substring << endl;
                    Term *newTerm = new Term(substring);
                    subTerms->push_back(newTerm);
                }
                pushValue--;
            }
        } else if (c == '*' || c == '/' || c == '+' || c == '-') {
            if (!substringActive) {
                
            }
        }
        i++;
    }
}

Term::Term()
{
    power = 1.0;
}

Term::Term(std::string input)
{
    previousOperator = none;
    subTerms = new vector<Term*>;
    parseInput(input);
}

