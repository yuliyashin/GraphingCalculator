#include "input.h"

Queue <Token*> tokenizeString(){
    Queue<Token*> inFix;
    string input;
    getline(cin,input);

    stringstream iss(input);
    string word;
    while(iss >> word) {
        determineType(word, inFix);
    }

//    cout << "INFIX: " << inFix << endl;
//    Queue<Token*> postFix = toPostFix(inFix);
//    cout << "POSTFIX: " << postFix << endl;
//    cout << "EVAL: " << eval(postFix, 20) << endl;
//    Queue<Token*> inFix;
//    string input;
//    getline(cin,input);

//    stringstream iss(input);
//    string word;
//    while(iss >> word) {
//        cout << "werd: "<< word << endl;
//        determineType(word, inFix);
//    }


//    cout << "INFIX: " << inFix << endl;
//    Queue<Token*> postFix = toPostFix(inFix);
//    cout << "postfixxx: " << postFix << endl;

//    double num = eval(postFix, 20);
//    cout << "we are crashing: " << num << endl;

    return inFix;
}


void determineType(string word, Queue<Token *>& inFix){
    if (word == "("){
        inFix.push(new LeftParenthesis());
    } else if (word == ")"){
        inFix.push(new RightParenthesis());
    } else if (word == "+"){
        inFix.push(new Operator('+'));
    } else if (word == "-"){
        inFix.push(new Operator('-'));
    } else if (word == "*"){
        inFix.push(new Operator('*'));
    } else if (word == "/"){
        inFix.push(new Operator('/'));
    } else if (word == "^"){
        inFix.push(new Operator('^'));
    } else if (word.length() == 3 && isalpha(word[0])){
        inFix.push(new Trig(word));
    } else if (word.length() == 1 && isalpha(word[0])){
        inFix.push(new Variable(word[0]));
    } else
        inFix.push(new Operand(stoi(word)));
}
