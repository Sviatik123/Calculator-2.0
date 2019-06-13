#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<string>
#include"parser.h"
#include"converter.h"
#include<cmath>

class Calculator
{
public:
    Calculator();
    Calculator(std::string expression);
    void calculate();
    void printResult();
    double getResult();
private:
    std::string exp;
    std::string polExp;
    double result;
};

#endif // CALCULATOR_H
