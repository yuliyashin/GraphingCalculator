#ifndef VARIABLE_H
#define VARIABLE_H
#include "../../!include/RPN/token.h"


class Variable : public Token
{
public:
    Variable(char var);
    double get_value(){
        return _var;
    }

    void print(ostream& outs = cout) const{
        outs << _var;
    }

private:
    char _var;
};

#endif // VARIABLE_H
