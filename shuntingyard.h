#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H
#include "../!include/RPN/token.h"
#include "../!include/RPN/queue.h"
#include "../!include/RPN/const.h"
#include "../!include/RPN/stack.h"
#include "../!include/RPN/operator.h"
#include "../!include/RPN/operand.h"
#include "../!include/RPN/variable.h"
#include "../!include/RPN/trig.h"

Queue<Token*> toPostFix(Queue<Token*> inFix){
    Queue<Token*> postFix;
    Stack<Token*> operations;
    bool oneVariable = false;
    if (inFix.getSize() == 1){
        oneVariable = true;
    }

    while (!inFix.empty()){
        Token* token = inFix.pop();
        switch (token->get_type()){
        case OPERAND:
            postFix.push(token);
            break;

        case OPERATOR:
            while (!operations.empty() &&
                   operations.top()->get_type() != OPEN_PAREN &&
                   static_cast<Operator*>(operations.top())->checkPrecedence() >= static_cast<Operator*>(token)->checkPrecedence()){
                //pop operator stack and push into postfix q:
                // as long as:
                //1. stack is not empty
                //*2. top of stack is not open paren
                //3. prec of top of stack is greater or equal to
                //      prec of this token.
                postFix.push(operations.pop());
            }
            operations.push(token);
            break;
        case OPEN_PAREN:
            operations.push(token);
            break;
        case CLOSED_PAREN:
            while(operations.top()->get_type() != OPEN_PAREN){
                postFix.push(operations.pop());
            }
            operations.pop(); //pop off (
            break;
        case VARIABLE:
            if (oneVariable == true) {
                postFix.push(token);
            } else {
                postFix.push(token);
                postFix.push(new Operator('*'));
            }
            break;

        case TRIG:
            postFix.push(token);
            break;
        }

    }
    while (!operations.empty()){
        Token* tp = operations.pop();       // acounts for remaining stuff in stack
        postFix.push(tp);
    }

    return postFix;
}

double eval(Queue<Token*> postFix, double x){
    Stack<double> stack;
    while (!postFix.empty()) {
        Token* token = postFix.pop();
        switch (token->get_type()){
            case OPERAND: {
                double value = static_cast <Operand*>(token)->get_value();
                stack.push(value);
                break;
            }
            case OPERATOR:{
                double RHS = (stack.pop());
                double LHS = (stack.pop());
                double value = static_cast<Operator*>(token)->calculate(LHS, RHS);
                stack.push(value);
                break;
            }
            case VARIABLE:
                stack.push(x);
                break;
            case TRIG: {
//                Token* nextToken = postFix.pop();
//                while (nextToken->get_type()) {

//                }
                double value = static_cast<Trig*>(token)->calculate(x);
                stack.push(value);
                break;
            }
        }
    }
    return stack.top();
}

//sin ( x )

//sin
//(
//x
//)

//sin(x)


//sqt sin
// sqt(10) * sin(10)
#endif // SHUNTINGYARD_H
