#include "converter.h"
#include<vector>
#include<algorithm>

Converter::Converter()
{

}

bool isHigherPriority(char symb1, std::string symb2)
{
    if(symb1 == '+' || symb1 == '-')
    {
        std::vector<std::string> higherPriorityActions {"+", "-", "*", "/", "^", "sin", "cos", "tg", "ctg", "log"};
        bool res = std::find(higherPriorityActions.begin(), higherPriorityActions.end(), symb2) != higherPriorityActions.end();
        return res;
    }
    else if (symb1 == '*' || symb1 == '/')
    {
        std::vector<std::string> higherPriorityActions {"*", "/", "^", "sin", "cos", "tg", "ctg", "log"};
        bool res = std::find(higherPriorityActions.begin(), higherPriorityActions.end(), symb2) != higherPriorityActions.end();
        return res;
    }
    else if (symb1 == '^')
    {
        std::vector<std::string> higherPriorityActions {"^", "sin", "cos", "tg", "ctg", "log"};
        bool res = std::find(higherPriorityActions.begin(), higherPriorityActions.end(), symb2) != higherPriorityActions.end();
        return res;
    }
    else
    {
        std::vector<std::string> higherPriorityActions {"sin", "cos", "tg", "ctg", "log"};
        bool res = std::find(higherPriorityActions.begin(), higherPriorityActions.end(), symb2) != higherPriorityActions.end();
        return res;
    }
}

std::string Converter::convert(std::string exp)
{
    std::string polExp;
    polExp = "";
    exp += " ";
    std::stack<std::string> expression;
    size_t length = exp.length();
    for (size_t i = 0; i < length - 1; i++)
    {
        if (exp.at(i) >= 48 && exp.at(i) <= 57)
        {
            polExp += exp.at(i);
            while ((exp.at(i + 1) >= 48 && exp.at(i + 1) <= 57) || exp.at(i + 1) == '.' || exp.at(i + 1) == ',')
            {
                polExp += exp.at(i + 1);
                i++;
            }
            polExp += " ";
        }
        else if (exp.at(i) == ' ')
        {
            continue;
        }
        else if (exp.at(i) == '(')
        {
            expression.push("(");
        }
        else if (exp.at(i) == ')')
        {
            while (expression.top() != "(")
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.pop();
        }
        else if (exp.at(i) == '+')
        {
            while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("+");
        }
        else if (exp.at(i) == '-')
        {
            if (i == 0 || exp.at(i - 1) == '(')
            {
                polExp += exp.at(i);
                while ((exp.at(i + 1) >= 48 && exp.at(i + 1) <= 57) || exp.at(i + 1) == '.' || exp.at(i + 1) == ',')
                {
                    polExp += exp.at(i + 1);
                    i++;
                }
                polExp += " ";
            }
            else
            {
                while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
                {
                    polExp += expression.top();
                    expression.pop();
                    polExp += ' ';
                }
                expression.push("-");
            }
        }
        else if (exp.at(i) == '*')
        {
            while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("*");
        }
        else if (exp.at(i) == '/')
        {
            while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("/");
        }
        else if (exp.at(i) == '^')
        {
            while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("^");
        }
        //sin
        else if (exp.at(i) == 's')
        {
            while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("sin");
            i+=2;
        }
        //cos
        else if (exp.at(i) == 'c' && exp.at(i + 1) == 'o')
        {
            while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("cos");
            i+=2;
        }
        //tg
        else if (exp.at(i) == 't')
        {
            while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("tg");
            i++;
        }
        //ctg
        else if (exp.at(i) == 'c' && exp.at(i + 1) == 't')
        {
            while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("ctg");
            i+=2;
        }
        //log
        else if (exp.at(i) == 'l')
        {
            while (!expression.empty() && isHigherPriority(exp.at(i), expression.top()))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("log");
            i+=2;
        }
    }
    while (!expression.empty())
    {
        polExp += expression.top();
        expression.pop();
        polExp += " ";
    }
    return polExp;
}

