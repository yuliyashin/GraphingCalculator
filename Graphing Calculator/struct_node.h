#ifndef STRUCTNODE_H
#define STRUCTNODE_H
#include <iostream>
using namespace std;

template <typename T>
struct node{
    T _item;
    node<T>* _next;

    //I don't need this:
    //node():_item(T()), _next(NULL){
    //blank
    //}

    node(const T& item=T(), node<T>*next = NULL): // T() is for setting the item to be a constructor for that data type,
        _item(item), _next(next){               // int = 0, string = ""
    }
};

#endif // STRUCTNODE_H
