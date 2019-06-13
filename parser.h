#ifndef PARSER_H
#define PARSER_H
#include<string>
#include<iostream>
#include<numeric>


class Parser
{
public:
    Parser();
    std::string parse(int size, char* arr[]);
    std::string parse();
private:
};

#endif // PARSER_H
