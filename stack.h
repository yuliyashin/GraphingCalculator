#ifndef STACK_H
#define STACK_H
#include <cassert>
#include "list.h"
template <typename T>
class Stack {
public:
    Stack();
    void push(const T& item);
    T pop();
    T top();
    bool empty();

    friend ostream& operator <<(ostream& outs,          //insertion operator for list
                                const Stack<T>& l)
    {
//        outs << l._stack;
        node<T>* walker = l._stack.Begin();
        for (int i = 0; i < l.size; i++)
        {
            outs << "[" << walker->_item << "]->";
            walker = walker->_next;
        }
        outs << "|||";
        return outs;
    }

private:
    int size; //determine if needed
    List<T> _stack;
};

template <typename T>
Stack<T>::Stack()
{
    size = 0;
}

template <typename T>
void Stack<T>::push(const T& item)
{
    _stack.InsertHead(item);
    size++;
}

template <typename T>
T Stack<T>::pop()
{
    assert(!empty());
    node<T>* head = _stack.Begin();
//    T hold = head->_item;
    T hold = _stack.Delete(head);
    size--;

//    assert(!empty());
//    node<T>* head = _stack.Begin();
//    T hold = head->_item;
//    _stack.Delete(head);                //account for deleted item
//    size--;
    return hold;
}

template <typename T>
T Stack<T>::top()
{
    return _stack.Begin()->_item;
}

template <typename T>
bool Stack<T>::empty()
{
    if (size == 0)
        return true;
    else
        return false;
}

#endif // STACK_H
