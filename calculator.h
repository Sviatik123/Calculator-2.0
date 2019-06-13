#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<string>
#include"converter.h"
#include"validator.h"
#include<cmath>

class Calculator
{
public:
    Calculator();
    Calculator(std::string expression);
    void calculate();
    double getResult();
    bool getIsValid();
private:
    std::string exp;
    std::string polExp;
    double result;
    bool isValid;
};

#endif // CALCULATOR_H
