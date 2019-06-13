#include "validator.h"
#include<vector>
#include<algorithm>

Validator::Validator(){}

bool Validator::validate(std::string expression)
{
    std::vector<char> validSymbols {'+', '-', '*', '/', '^', '.', ',', 's', 'i', 'n', 'c', 'o', 't', 'g', 'l', ' ', '(', ')'};
    size_t length = expression.length();
    for (size_t i = 0; i < length; i++)
    {
        bool isValidSymb = std::find(validSymbols.begin(), validSymbols.end(), expression.at(i)) != validSymbols.end();
        if((expression.at(i) < 48 || expression.at(i) > 57) && !isValidSymb)
        {
            return false;
        }
    }
    return true;
}
