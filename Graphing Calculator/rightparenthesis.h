#ifndef RIGHTPARENTHESIS_H
#define RIGHTPARENTHESIS_H
#include "../../!include/RPN/token.h"

class RightParenthesis : public Token
{
public:
    RightParenthesis();
    void print(ostream& outs = cout) const{
        outs << _rightParenthesis;
    }
    char get_parenthesis() {
        return _rightParenthesis;
    }
private:
    char _rightParenthesis;
};

#endif // RIGHTPARENTHESIS_H
