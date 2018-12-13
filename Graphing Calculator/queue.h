#ifndef QUEUE_H
#define QUEUE_H
#include "struct_node.h"
#include "linked_list.h"

template <typename T>
class Queue {

public:
    Queue();
    ~Queue();
    Queue(const Queue& other);
    Queue<T>& operator=(const Queue& rhs);
    void push(const T& item);
    T pop();
    T front();
    bool empty();
    int getSize();
    friend ostream& operator <<(ostream& outs,          //insertion operator for list
                                const Queue<T>& l)
    {
        node<T>* walker = l._front;
        for (int i = 0; i < l.size; i++)
        {
            outs << "[ " << walker->_item << "]->";
            walker = walker->_next;
        }
        outs << "|||";
        return outs;
    }

private:
    int size;
    node<T>* _front;
    node<T>* _rear;
};

template <typename T>
Queue<T>::~Queue()
{
    clearList(_front);
    _front = NULL;
    _rear = NULL;
    size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue& other){
    const bool debug = false;
    this->size = other.size;
    this->_rear = copy_list(this->_front, other._front);
    if (debug){
        cout<<"Q copy CTOR called."<<endl;
    }
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& rhs)
{
    if (this == & rhs)
        return *this;

    clearList(this->_front);
    this->_front = NULL;
    this->size = rhs.size;
    this->_rear = copy_list(this->_front, rhs._front);
    return *this;
}

template <typename T>
Queue<T>::Queue()
{
    _front = NULL;
    _rear = NULL;      // A queue is empty if the front and back are both pointing to NULL
    size = 0;
}

template <typename T>
void Queue<T>::push(const T& item)
{
    if (size == 0){
        _rear = insertHead(_front, item);

    } else{
        _rear = insertAfter(_front, _rear, item);
    }           // push an item to the end of the list
    size++;
}

template <typename T>
T Queue<T>::pop()
{
    assert(!empty());
    size--;
    T hold = eraseHead(_front);
    if (size == 0){
        _front = NULL;
        _rear = NULL;

        //        cout << "d " << endl;
        //        _rear = NULL;
        //        cout << "e: " << endl;
    }
    return hold;
}

template <typename T>
T Queue<T>::front()
{
    return _front->_item;
}

template <typename T>
bool Queue<T>::empty()
{
    return (_front == NULL && _rear == NULL);
}

template <typename T>
int Queue<T>::getSize()
{
    return size;
}

#endif // QUEUE_H
