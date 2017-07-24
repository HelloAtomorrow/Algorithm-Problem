#include <iostream>
#include "myList.h"
using namespace std;


CMyList::CMyList()
{
    NIL = new SListNode;
    NIL->value = NULL;
    NIL->p_prev = NIL;
    NIL->p_next = NIL;
}


CMyList::~CMyList()
{
    SListNode *node = NIL->p_next;
    while (NIL->p_next->value)
    {
        NIL->p_next = node->p_next;
        delete node;
        node = NIL->p_next;
    }
    delete NIL;
}


void CMyList::listPrint()
{
    SListNode *p_print = NIL->p_next;
    while (p_print->value)
    {
        cout << "--->" << p_print->value;
        p_print = p_print->p_next;
    }
    cout << endl;

}


SListNode *CMyList::listSearch(int value)
{
    SListNode *p_search = NIL->p_next;
    while ((p_search->p_next->value) && (p_search->value != value))
    {
        p_search = p_search->p_next;
    }
    return p_search;
}


void CMyList::listInsert(int value)
{
    SListNode *p_insert = new SListNode;
    p_insert->value = value;
    p_insert->p_next = NIL->p_next;
    NIL->p_next->p_prev = p_insert;
    NIL->p_next = p_insert;
    p_insert->p_prev = NIL;
}


int CMyList::listDelete(SListNode *p_delete)
{
    p_delete->p_prev->p_next = p_delete->p_next;
    p_delete->p_next->p_prev = p_delete->p_prev;
    int value = p_delete->value;
    delete p_delete;
    return value;
}

/*
int main()
{
    cout << "List" << endl;
    CMyList myList;
    for (int i = 0; i < 5; i++)
    {
        //cout << i << endl;
        myList.listInsert(i);
    }
    myList.listPrint();
    
    SListNode *p_search = myList.listSearch(3);
    cout << p_search->value << endl;
    
    SListNode *p_delete = p_search;
    int value = myList.listDelete(p_delete);
    cout << value << endl;
    myList.listPrint();
}
*/