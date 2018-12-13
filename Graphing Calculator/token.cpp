#include "token.h"

Token::Token(int type): _type(type){}
//ostream& operator <<(ostream& outs, const Token& token){
//    token.print(outs);
//    return outs;
//}

void Token::print(ostream &outs) const{
    outs<<"TOKEN: DON't ^%#$# call me again!"<<endl;
    //Blank
}
