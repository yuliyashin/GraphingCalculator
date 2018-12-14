#ifndef TRIG_H
#define TRIG_H
#include <iostream>
#include "token.h"
using namespace std;

class Trig : public Token
{
public:
    Trig(string trig);

    void print(ostream& outs = cout) const{
        outs << _trig;
    }

    string get_trig() {
        return _trig;
    }

    double calculate(double value);

private:
    string _trig;
};

#endif // TRIG_H
