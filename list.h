#ifndef LIST_H
#define LIST_H
#include "struct_node.h"
#include "linked_list.h"

template <typename T>
class List
{
public:
    List(); //x
    ~List(); //x
    List(const List<T> &copyThis); //x
    List& operator =(const List& RHS); //x

    node<T>* InsertHead(T i); //x           //inset i at the head of list

    node<T>* InsertAfter(T i, //x          //insert i after iMarker
                         node<T>* iMarker);

    node<T>* InsertBefore(T i, //x          //insert i before iMarker
                          node<T>* iMarker);

    node<T>* InsertSorted(T i);         //insert i. Assume sorted list



    T Delete(node<T>* iMarker); //x        //delete node pointed to by iMarker


    void Print() const; //x                              //print the list

    node<T>* Search(const T &key); //x      //return pointer to node containing
    //  key. NULL if not there

    node<T>* Prev(node<T>* iMarker); //x   //get the previous node to iMarker


    T& operator[](int index); //x                //return the item at index

    node<T>* Begin() const;  //x                   //return the head of the list

    node<T>* End() const;                       //return the tail of the list
    //  if you ever have to use this                                           //  function, you need to redesign
    //  your program.
        template <class U>
        friend ostream& operator <<(ostream& outs,          //insertion operator for list
                                    const List<U>& l)
        {
            printList(l.head);
            return outs;
        }
private:
    node<T>* head;
};

template<typename T>
List<T>::List()
{
    head = NULL;
}

template<typename T>
List<T>::~List()
{
    delete[] head;
}

template<typename T>
List<T>::List(const List<T> &copyThis)
{
    head = copyList(copyThis.head);
}

template<typename T>
List<T>& List<T>::operator =(const List& RHS)
{
    if(this == &RHS)
        return *this;

    delete[] head;
    head = copyList(RHS.head);
    return *this;
}

template<typename T>
node<T>* List<T>::InsertHead(T i)
{
    return insertHead(head, i);
}

template<typename T>
node<T>* List<T>::InsertAfter(T i, node<T>* iMarker)
{
    return insertAfter(head, iMarker, i);
}

template<typename T>
node<T>* List<T>::InsertBefore(T i, node<T>* iMarker)
{
    return insertBefore(head, iMarker, i);
}

template<typename T>
node<T>* List<T>::InsertSorted(T i)
{

}         //insert i. Assume sorted list

template<typename T>
T List<T>::Delete(node<T>* iMarker)
{
    T item = deleteNode(head, iMarker);
    return item;
}         //delete node pointed to by iMarker

template<typename T>
void List<T>::Print() const
{
    printList(head);
}                                 //print the list

template<typename T>
node<T>* List<T>::Search(const T &key)
{
    return searchList(head, key);
}

template<typename T>
node<T>* List<T>::Prev(node<T>* iMarker)
{
    return previousNode(head, iMarker);
}

template<typename T>
T& List<T>::operator[](int index)
{
    return At(head, index);
}                   //return the item at index

template<typename T>
node<T>* List<T>::Begin() const
{
    return head;
}                  //return the head of the list

template<typename T>
node<T>* List<T>::End() const
{
    return LastNode(head);
}

//template <class T>
//ostream& operator <<(ostream& outs,          //insertion operator for list
//                     const List<T>& l)
//{
//    node<T>* walker = l.head;
////    while walker 1
//}

#endif // LIST_H
