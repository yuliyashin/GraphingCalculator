#ifndef LEFTPARENTHESIS_H
#define LEFTPARENTHESIS_H
#include "../../!include/RPN/token.h"

class LeftParenthesis : public Token
{
public:
    LeftParenthesis();
    void print(ostream& outs = cout) const{
        outs << _leftParenthesis;
    }
    char get_parenthesis() {
        return _leftParenthesis;
    }
private:
    char _leftParenthesis;
};

#endif // LEFTPARENTHESIS_H
