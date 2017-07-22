#include <iostream>
#include "myList.h"
using namespace std;


template <typename elemType>
CMyList<elemType>::CMyList()
{
    NIL = new SListNode<elemType>;
    NIL->value = NULL;
    NIL->p_prev = NIL;
    NIL->p_next = NIL;
}


template <typename elemType>
CMyList<elemType>::~CMyList()
{
    SListNode<elemType> *node = NIL->p_next;
    while (NIL->p_next->value)
    {
        NIL->p_next = node->p_next;
        delete node;
        node = NIL->p_next;
    }
    delete NIL;
}


template <typename elemType>
void CMyList<elemType>::listPrint()
{
    SListNode<elemType> *p_print = NIL->p_next;
    while (p_print->value)
    {
        cout << p_print->value << "---" ;
        p_print = p_print->p_next;
    }
    cout << endl;

}


template <typename elemType>
SListNode<elemType> *CMyList<elemType>::listSearch(elemType value)
{
    SListNode<elemType> *p_search = NIL->p_next;
    while ((p_search->p_next->value) && (p_search->value != value))
    {
        p_search = p_search->p_next;
    }
    return p_search;
}


template <typename elemType>
void CMyList<elemType>::listInsert(elemType value)
{
    SListNode<elemType> *p_insert = new SListNode<elemType>;
    p_insert->value = value;
    p_insert->p_next = NIL->p_next;
    NIL->p_next->p_prev = p_insert;
    NIL->p_next = p_insert;
    p_insert->p_prev = NIL;
}


template <typename elemType>
elemType CMyList<elemType>::listDelete(SListNode<elemType> *p_delete)
{
    p_delete->p_prev->p_next = p_delete->p_next;
    p_delete->p_next->p_prev = p_delete->p_prev;
    elemType value = p_delete->value;
    delete p_delete;
    return value;
}


int main()
{
    cout << "List" << endl;
    CMyList<int> myList;
    for (int i = 0; i < 5; i++)
    {
        //cout << i << endl;
        myList.listInsert(i);
    }
    myList.listPrint();
    
    SListNode<int> *p_search = myList.listSearch(3);
    cout << p_search->value << endl;
    
    SListNode<int> *p_delete = p_search;
    int value = myList.listDelete(p_delete);
    cout << value << endl;
    myList.listPrint();
}