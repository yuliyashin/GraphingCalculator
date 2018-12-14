#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <cassert>
#include <iostream>
#include "struct_node.h"
using namespace std;

//=========================== PROTOTYPES ===================================

template <typename T> //X
node<T>* insertHead(node<T>* &head_ptr, const T& item); //insert item to the start of list
//return pointer to inserted node

template <typename T> //X
void printList(node<T>* head_ptr);

template <typename T> //X
T eraseHead(node<T>*& head_ptr);           //Delete node at the head

template <typename T>
void PrintList_backwards(node<T> *head);            //recursive fun! :)

template <typename T> //x
node<T>* searchList(node<T>* head,          //return ptr to key or NULL
                    T key);

template <typename T> //x
node<T>* insertAfter(node<T>*& head,        //insert after ptr
                     node<T> *afterThis,
                     T insertThis);

template <typename T> // x
node<T>* insertBefore(node<T>*& head,       //insert before ptr
                      node<T>* beforeThis,
                      T insertThis);

template <typename T> // x
node<T>* previousNode(node<T>* head,        //ptr to previous node
                      node<T>* prevToThis);

template <typename T> // x
T deleteNode(node<T>*&head,                 //delete, return item
             node<T>* deleteThis);

template <typename T> // x
node<T>* copyList(node<T>* head);           //duplicate list and return the key to the new list

template <typename T>
node<T>* copy_list(node<T>*&_dest, node<T>*&_src); //we want to return the end node pointer for Queue

template <typename T> // ?
void clearList(node<T>*& head);                     //delete all the nodes

template <typename T> // x
T& At(node<T>* head, int pos);              //_item at this position

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
node<T>* InsertSorted(node<T>* &head,       //insert
                      const T &item, bool ascending=true);
template <typename T>
node<T>* insertSortedUnique(node<T>* &head, const T &item, bool ascending = true);

//template <typename T>
//node<T>* InsertSorted_and_add(node<T>* &head, //insert or add if a dup
//                              T item,
//                              bool ascending=true);

template <typename T>
node<T>* WhereThisGoes(node<T>* head,         //node after which this
                       const T &item,             //    item goes
                       bool ascending=true);      //order: 0 ascending
template <typename T>
node<T>* LastNode(node<T>* head);            //Last Node in the list


// ========================= DEFINITIONS ==================================

template<typename T>
node<T>* insertHead(node<T>* &head_ptr, const T& item){
    /*
     * head_ptr: by reference arg. pointing to the list
     * item: to be inserted.
     *
     * create a new node with item as payload.
     * insert at the head of the list
     * return pointer to this inserted node
     */

    //1. create a new node.
    node<T>* temp = new node<T>(item);

    //2. temp's next points to where head_ptr points to
    temp->_next = head_ptr; //temp->next is the "sticker" on the box

    //3. point head_ptr to where temp is pointing to
    head_ptr = temp;

    //return head_ptr;
    return head_ptr;
}

template<typename T>
void printList(node<T>* head_ptr){
    /*
    * print list pointed to by head_ptr
    */
    node<T>* walker;
    walker = head_ptr;
    while (walker != NULL){
        cout<<"["<<walker->_item<<"]->";
        walker = walker->_next;
    }
    cout<<"|||"<<endl;
}

template <typename T>
T eraseHead(node<T>*& head_ptr){           //Delete node at the head
    //assert that the list is not empty()
    //    assert(!empty(head_ptr));
    assert(head_ptr!= nullptr);
    //0. a T variable and store item from head node
    T hold_this = head_ptr->_item;
    //1. declare a node ptr to hold the removed node
    node<T>* temp = new node<T>(head_ptr->_item);
    //2. temp = head: point temp to where head is pointing to
    head_ptr = head_ptr->_next;
    //3. head points to the next node in the chain:
    //head_ptr = temp->_next;
    //        head_ptr = head_ptr->_next;

    //delete temp: release the space temp is pointing to
    //    delete temp;
    delete temp;
    //return T variable
    return hold_this;
}

template <typename T>
node<T>* searchList(node<T>* head, T key)
{
    node<T>* walker = head;
    while (walker != NULL)
    {
        if (walker->_item == key)
            return walker;
        else
            walker = walker->_next;
    }
    return NULL;
}

template <typename T>
node<T>* insertAfter(node<T>*& head, node<T>* afterThis, T insertThis)
{
    node<T>* insertedNode;
    if (head == NULL){
        insertedNode = insertHead(head, insertThis);
    }
    else{
        insertedNode = insertHead(afterThis->_next, insertThis);
    }
    return insertedNode;
}

template <typename T>
node<T>* insertBefore(node<T>*& head, node<T>* beforeThis, T insertThis)
{
    node<T>* prevToThis = previousNode(head, beforeThis);
    return insertAfter(head, prevToThis, insertThis);
}

template <typename T>
node<T>* previousNode(node<T>* head, node<T>* prevToThis)
{
    if (prevToThis == head)
        return NULL;
    node<T>* beforeThisNode = head;
    node<T>* thisNode = head;
    while (thisNode != prevToThis)
    {
//        cout << "reaching for"  << endl;
        beforeThisNode = thisNode;
        thisNode = thisNode->_next;
    }
    return beforeThisNode;
}

template <typename T>
T deleteNode(node<T>*& head, node<T>* deleteThis)
{
    node<T>* isNow = previousNode(head, deleteThis);

    if (isNow == NULL) {
//        T item = head->_item;
//        node<T>* temp = head;
//        head = head->_next;
//        delete temp;
        T item = eraseHead(head);
        return item;
    } else {
        isNow->_next = deleteThis-> _next;
        T item = eraseHead(deleteThis);
        return item;
    }
}

template <typename T>
node<T>* copy_list(node<T>*& dest, node<T>* src)
{
    assert(src != NULL); // make sure the list we're copying from isn't empty
    insertHead(dest, src->_item);   // inserts the head item of the old list
    node<T>* newListWalker = dest; // sets a nodewalker to the beginning of new queue
    node<T>* oldListWalker = src->_next; // sets a walker at the second item of original list
    while (oldListWalker != NULL)
    {
        newListWalker = insertAfter(dest, newListWalker, oldListWalker->_item);
        oldListWalker = oldListWalker->_next;
    }

    return newListWalker; // should return the end of the the new list
}

template <typename T>
node<T>* copyList(node<T>* head)
{
    node<T>* newHeadPtr = new node<T>(head->_item); //first item is copied into new node, placed at head
    node<T>* oldHeadWalker = head->_next; //start at second item of original list
    node<T>* newHeadWalker = newHeadPtr;

    while (oldHeadWalker != NULL)
    {
        newHeadWalker = insertAfter(newHeadPtr, newHeadWalker, oldHeadWalker->_item);
        oldHeadWalker = oldHeadWalker->_next;
    }

    return newHeadPtr;
}

template <typename T>
void clearList(node<T>*& head)
{
    while (head != NULL)
        eraseHead(head);
}

template <typename T>
T& At(node<T>* head, int pos)
{
    node<T>* getter = head;
    for (int i = 0; i < pos; i++)
    {                                 //pos starting from index (0)
        getter = getter->_next;
    }
    return getter->_item;
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
node<T>* InsertSorted(node<T>* &head, const T &item, bool ascending)
{
    node<T>* here = WhereThisGoes(head, item, ascending);
    if (here == NULL)
    {
        return insertHead(head, item);
    }
    else
    {
        return insertAfter(head, here, item);
    }
}

//template <typename T>
//node<T>* InsertSorted_and_add(node<T>* &head, T item, bool ascending)
//{
//    node<T>* hold = WhereThisGoes(head, item, ascending);
//    hold->item = hold->item + item;
//    return hold;
//}

template <typename T>

node<T>* insertSortedUnique(node<T>* &head, const T &item, bool ascending)
{
    node<T>* holder = searchList(head, item);
    if (holder == NULL)
        return InsertSorted(head, item, ascending);
    else
    {
        holder->_item += item;
        return holder;
    }


//    node<T>* hold = Inserted(head, item, ascending);
//    if (hold->_item == item)
//    return InsertSorted_and_add;
//    else
//        return InsertSorted;
}

template <typename T>
node<T>* WhereThisGoes(node<T>* head, const T &item, bool ascending)
{
    node<T>* thisGoes = head;
    if (ascending)
    {
        if (head == NULL || item < head->_item )
        return NULL;
        while (thisGoes->_next != NULL && thisGoes->_next->_item < item)
        {
            thisGoes = thisGoes->_next;
        }
        return thisGoes;
    }

    else
    {
        if (head == NULL || item > head->_item )
        return NULL;
        while (thisGoes->_next != NULL && thisGoes->_next->_item > item)
        {
            thisGoes = thisGoes->_next;
        }
        return thisGoes;
    }
}

template <typename T>
node<T>* LastNode(node<T>* head)
{
    if (head == NULL){
        return nullptr;
    }

    node<T>* nodeWalker = head;
    while (nodeWalker->_next != NULL)
    {
        nodeWalker = nodeWalker->_next;
    }
    return nodeWalker;
}

#endif // LINKED_LIST_H
