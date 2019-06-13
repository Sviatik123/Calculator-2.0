#include "converter.h"
#include<vector>

Converter::Converter()
{

}

bool isHigherPriority(char symb1, std::string symb2)
{
    if(symb1 == '+' || symb1 == '-')
    {

    }
    else if (symb1 == '*' || symb1 == '/')
    {

    }
    else if (symb1 == '^')
    {

    }
    else
    {

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
//        bool isNextNumber = exp.at(i + 1) != '+' && exp.at(i + 1) != '-' && exp.at(i + 1) != '*' && exp.at(i + 1) != '/' &&
//                            exp.at(i + 1) != '^' && exp.at(i + 1) != ' ' && exp.at(i + 1) != '(' && exp.at(i + 1) != ')';
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
//            bool isHigherPriority = !expression.empty() && (expression.top() == "+" || expression.top() == "-" || expression.top() == "*" ||
//                                                            expression.top() == "/" || expression.top() == "^" || expression.top() == "sin" ||
//                                                            expression.top() == "cos" || expression.top() == "tg" || expression.top() == "ctg");
            while (!expression.empty() && (expression.top() == "+" || expression.top() == "-" || expression.top() == "*" ||
                                           expression.top() == "/" || expression.top() == "^" || expression.top() == "sin" ||
                                           expression.top() == "cos" || expression.top() == "tg" || expression.top() == "ctg" ||
                                           expression.top() == "log"))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("+");
        }
        else if (exp.at(i) == '-')
        {
            if (i == 0 || exp[i - 1] == '(')
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
//                bool isHigherPriority = !expression.empty() && (expression.top() == "+" || expression.top() == "-" || expression.top() == "*" ||
//                                                                expression.top() == "/" || expression.top() == "^" || expression.top() == "sin" ||
//                                                                expression.top() == "cos" || expression.top() == "tg" || expression.top() == "ctg");
                while (!expression.empty() && (expression.top() == "+" || expression.top() == "-" || expression.top() == "*" ||
                                               expression.top() == "/" || expression.top() == "^" || expression.top() == "sin" ||
                                               expression.top() == "cos" || expression.top() == "tg" || expression.top() == "ctg" ||
                                               expression.top() == "log"))
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
//            bool isHigherPriority = !expression.empty() && (expression.top() == "*" || expression.top() == "/" || expression.top() == "^" ||
//                                                            expression.top() == "sin" || expression.top() == "cos" ||
//                                                            expression.top() == "tg" || expression.top() == "ctg");
            while (!expression.empty() && (expression.top() == "*" || expression.top() == "/" || expression.top() == "^" ||
                                           expression.top() == "sin" || expression.top() == "cos" || expression.top() == "tg" ||
                                           expression.top() == "ctg" || expression.top() == "log"))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("*");
        }
        else if (exp.at(i) == '/')
        {
//            bool isHigherPriority = !expression.empty() && (expression.top() == "*" || expression.top() == "/" || expression.top() == "^" ||
//                                                            expression.top() == "sin" || expression.top() == "cos" ||
//                                                            expression.top() == "tg" || expression.top() == "ctg");
            while (!expression.empty() && (expression.top() == "*" || expression.top() == "/" || expression.top() == "^" ||
                                           expression.top() == "sin" || expression.top() == "cos" || expression.top() == "tg" ||
                                           expression.top() == "ctg" || expression.top() == "log"))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("/");
        }
        else if (exp.at(i) == '^')
        {
//            bool isHigherPriority = !expression.empty() &&  (expression.top() == "^" || expression.top() == "sin" || expression.top() == "cos" ||
//                                                             expression.top() == "tg" || expression.top() == "ctg");
            while (!expression.empty() &&  (expression.top() == "^" || expression.top() == "sin" || expression.top() == "cos" ||
                                         expression.top() == "tg" || expression.top() == "ctg" || expression.top() == "log"))
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
//                bool isHigherPriority = !expression.empty() &&  (expression.top() == "sin" || expression.top() == "cos" ||
//                                                                 expression.top() == "tg" || expression.top() == "ctg");
                while (!expression.empty() &&  (expression.top() == "sin" || expression.top() == "cos" ||
                                                expression.top() == "tg" || expression.top() == "ctg" || expression.top() == "log"))
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
//            bool isHigherPriority = !expression.empty() &&  (expression.top() == "sin" || expression.top() == "cos" ||
//                                                             expression.top() == "tg" || expression.top() == "ctg");
            while (!expression.empty() &&  (expression.top() == "sin" || expression.top() == "cos" ||
                                            expression.top() == "tg" || expression.top() == "ctg" || expression.top() == "log"))
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
//            bool isHigherPriority = !expression.empty() &&  (expression.top() == "sin" || expression.top() == "cos" ||
//                                                             expression.top() == "tg" || expression.top() == "ctg");
            while (!expression.empty() &&  (expression.top() == "sin" || expression.top() == "cos" ||
                                            expression.top() == "tg" || expression.top() == "ctg" || expression.top() == "log"))
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
//            bool isHigherPriority = !expression.empty() &&  (expression.top() == "sin" || expression.top() == "cos" ||
//                                                             expression.top() == "tg" || expression.top() == "ctg");
            while (!expression.empty() &&  (expression.top() == "sin" || expression.top() == "cos" ||
                                            expression.top() == "tg" || expression.top() == "ctg" || expression.top() == "log"))
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
            while (!expression.empty() &&  (expression.top() == "sin" || expression.top() == "cos" ||
                                            expression.top() == "tg" || expression.top() == "ctg" || expression.top() == "log"))
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

