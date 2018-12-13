#include "trig.h"
#include <cmath>

Trig::Trig(string trig) : Token(TRIG), _trig(trig){}

double Trig::calculate(double x){
    if (_trig == "sin"){
        return sin(x);
    }
    if (_trig == "cos"){
        return cos(x);
    }
    if (_trig == "tan"){
        return tan(x);
    }
    if (_trig == "sqt"){
        return sqrt(x);
    } else{
        cout << "Error in calculating trig";
        return -1;
    }
}

//sin ( x )
//INFIX: [ sin]->[ (]->[ x]->[ )]->|||

//sin ( x )
//POSTFIX: [ sin]->[ x]->|||

//sin ( 5 )
//POSTFIX: [ sin]->[ 5]->|||

//sin ( cos ( 5  ) )
//POSTFIX: [ sin]->[cos] ->[ 5]->|||

