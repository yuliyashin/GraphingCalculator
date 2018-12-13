#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include "token.h"
using namespace std;

class Operator : public Token
{
public:
    Operator(char op);
    void print(ostream& outs = cout) const{
        outs << _operation;
    }

    char get_operation() {
        return _operation;
    }

    double calculate(double LHS, double RHS);
    int checkPrecedence();

private:
    char _operation;
};

#endif // OPERATOR_H
