/*
hash table的链表实现方法：
思路就是用一个数组表示hash表，数组的每一个元素都是一个链表。
对于每个输入的值，通过hash算法计算得到hash值，
然后将输入的值存放到数组下标为hash值的链表上。
*/
#ifndef CHAINHASHTABLE_H
#define CHAINHASHTABLE_H
#include "myList.h"


const int MAX_TABLE_SIZE = 7;


class CMyChainHashTable
{
public:
    CMyChainHashTable();
    ~CMyChainHashTable();

    void chainHashPrint();
    int hashAlgorithm(int value);
    SListNode *chainHashSearch(int value);
    void chainHashInsert(int value);
    int chainHashDelete(SListNode *p_delete);

private: 
    CMyList m_hashTable[MAX_TABLE_SIZE];
};
#endif
