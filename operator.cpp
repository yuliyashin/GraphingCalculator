#include "operator.h"
#include <math.h> // pow

Operator::Operator(char op) : Token(OPERATOR), _operation(op){}

double Operator::calculate(double LHS, double RHS){
    switch(_operation) {
    case '+':
        return LHS + RHS;
    case '-':
        return LHS - RHS;
    case '*':
        return LHS * RHS;
    case '/':
        return LHS / RHS;
    case '^':
        return pow(LHS, RHS);
    default:
        cout << "Error in calculation";
        return -1;
    }
}

int Operator::checkPrecedence(){
    switch(_operation) {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        cout << "Error in Precedence";
        return -1;
    }
}

//december 13 10:15 AM in his office
//project is due on December 12
