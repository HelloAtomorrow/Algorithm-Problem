/*
用指针实现的双向链表：
包括了添加，删除，查找，打印四个功能。
添加操作要求给出需要添加的值，函数建立一个新的node，保存这个值，并添加到list头部。
删除操作要求给出需要删除的节点的指针，函数返回该节点的值，并删去节点。
查找操作要求给出需要查找的值，返回指向该值的指针。
打印操作依次将链表节点的值打印出来。
*/
#ifndef MYLIST_H
#define MYLIST_H

struct SListNode
{
    int value;
    SListNode *p_prev;
    SListNode *p_next;    
};


class CMyList
{
public:
    CMyList();
    ~CMyList();

    void listPrint();
    SListNode *listSearch(int value);
    void listInsert(int value);
    int listDelete(SListNode *p_delete);

private:
    SListNode *NIL;
};
#endif