#ifndef OPERAND_H
#define OPERAND_H
#include "token.h"

class Operand : public Token
{
public:
    Operand(double value);
    void print(ostream& outs = cout) const{
        cout << _value;
    }
    double get_value() {
        return _value;
    }

private:
    double _value;
};

#endif // OPERAND_H
