#include <iostream>
#include "chainHashTable.h"
using namespace std;


CMyChainHashTable::CMyChainHashTable()
{

}


CMyChainHashTable::~CMyChainHashTable()
{
    
}


void CMyChainHashTable::chainHashPrint()
{
    for (int i = 0; i < MAX_TABLE_SIZE; i++)
    {
        m_hashTable[i].listPrint();
    }
}


int CMyChainHashTable::hashAlgorithm(int value)
{
    int location = value % 7;
    return location;
}


SListNode *CMyChainHashTable::chainHashSearch(int value)
{
    int location = hashAlgorithm(value);
    SListNode *p_search = m_hashTable[location].listSearch(value);
    return p_search;
}


void CMyChainHashTable::chainHashInsert(int value)
{
    int location = hashAlgorithm(value);
    m_hashTable[location].listInsert(value);
}


int CMyChainHashTable::chainHashDelete(SListNode *p_delete)
{
    int value = p_delete->value;
    int location = hashAlgorithm(value);
    m_hashTable[location].listDelete(p_delete);
    return value;
}


int main()
{
    cout << "chainHashTable" << endl;
    CMyChainHashTable myChainHashTable;
    for (int i = 1; i < 10; i++)
    {
        myChainHashTable.chainHashInsert(i);
    }

    myChainHashTable.chainHashPrint();

    SListNode *p_search = myChainHashTable.chainHashSearch(8);
    cout << p_search->value << endl;

    SListNode *p_delete = p_search;
    int value = myChainHashTable.chainHashDelete(p_delete);

    myChainHashTable.chainHashPrint();
    return 0;
}