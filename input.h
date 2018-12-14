#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <sstream>
#include "../!include/RPN/queue.h"
#include "../!include/RPN/token.h"
#include "../!include/RPN/operator.h"
#include "../!include/RPN/trig.h"
#include "../!include/RPN/variable.h"
#include "../!include/RPN/operand.h"
#include "../../C++/!include/RPN/leftparenthesis.h"
#include "../../C++/!include/RPN/rightparenthesis.h"
#include "../../C++/!include/RPN/trig.h"

using namespace std;

void determineType(string word, Queue<Token*>& inFix);
Queue<Token*> tokenizeString();

#endif // INPUT_H
