#include "calculator.h"

Calculator::Calculator(std::string expression)
{
    Validator val;
    isValid = val.validate(expression);
    if(isValid)
    {
        exp = expression;
        Converter conv;
        polExp = conv.convert(exp);
    }
    else
    {
       exp = "";
       polExp = "";
    }
}

void Calculator::calculate()
{
    std::string inp = "";
    std::stack<double> expression;
    size_t length = polExp.length();
    for (size_t i = 0; i < length; i++)
    {
        if ((polExp.at(i) >= 48 && polExp.at(i) <= 57) || polExp.at(i) == '.' || polExp.at(i) == ',')
        {
            while (polExp.at(i) != ' ')
            {
                inp += polExp.at(i);
                i++;
            }
            double operand = stod(inp);
            expression.push(operand);
            inp = "";
            i--;
        }
        else if (polExp.at(i) == ' ')
        {
            continue;
        }
        else if (polExp.at(i) == '+')
        {
            double firstOper, secondOper;
            secondOper = expression.top();
            expression.pop();
            firstOper = expression.top();
            expression.pop();
            expression.push(firstOper + secondOper);
        }
        else if (polExp.at(i) == '-')
        {
            if (polExp.at(i + 1) == ' ')
            {
                double firstOper, secondOper;
                secondOper = expression.top();
                expression.pop();
                firstOper = expression.top();
                expression.pop();
                expression.push(firstOper - secondOper);
            }
            else
            {
                while (polExp.at(i) != ' ')
                {
                    inp += polExp.at(i);
                    i++;
                }
                double operand = stod(inp);
                expression.push(operand);
                inp = "";
                i--;
            }
        }
        else if (polExp.at(i) == '*')
        {
            double firstOper, secondOper;
            secondOper = expression.top();
            expression.pop();
            firstOper = expression.top();
            expression.pop();
            expression.push(firstOper * secondOper);
        }
        else if (polExp.at(i) == '/')
        {
            double firstOper, secondOper;
            secondOper = expression.top();
            expression.pop();
            firstOper = expression.top();
            expression.pop();
            expression.push(firstOper / secondOper);
        }
        else if (polExp.at(i) == '^')
        {
            double firstOper, secondOper;
            secondOper = expression.top();
            expression.pop();
            firstOper = expression.top();
            expression.pop();
            expression.push(pow(firstOper, secondOper));
        }
        //sin
        else if (polExp.at(i) == 's')
        {
            double operand = expression.top();
            expression.pop();
            expression.push(sin(operand));
            i+=2;
        }
        //cos
        else if (polExp.at(i) == 'c' && polExp.at(i + 1) == 'o')
        {
            double operand = expression.top();
            expression.pop();
            expression.push(cos(operand));
            i+=2;
        }
        //tg
        else if (polExp.at(i) == 't')
        {
            double operand = expression.top();
            expression.pop();
            expression.push(tan(operand));
            i++;
        }
        //ctg
        else if (polExp.at(i) == 'c' && polExp.at(i + 1) == 't')
        {
            double operand = expression.top();
            expression.pop();
            expression.push(1.0 / tan(operand));
            i+=2;
        }
        //log
        else if (polExp.at(i) == 'l')
        {
            double operand = expression.top();
            expression.pop();
            expression.push(log(operand));
            i+=2;
        }
    }
    result = expression.top();
}

double Calculator::getResult()
{
    return result;
}

bool Calculator::getIsValid()
{
    return isValid;
}
