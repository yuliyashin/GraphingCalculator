#ifndef TOKEN_H
#define TOKEN_H
#include "const.h"
#include <iostream>

using namespace std;

class Token
{
public:
    Token(int type);
    friend ostream& operator << (ostream& outs, const Token* P){
        P->print(outs);
        return outs;
    }
    virtual void print(ostream& outs = cout) const;
    int get_type() {return _type;}
private:
    int _type;
};
#endif // TOKEN_H
