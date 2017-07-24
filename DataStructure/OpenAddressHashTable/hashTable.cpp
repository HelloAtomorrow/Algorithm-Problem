#include <iostream>
#include "hashTable.h"
using namespace std;


CMyHashTable::CMyHashTable()
{
    for (int i = 0; i < MAX_TABLE_SIZE; ++i)
    {
        m_hashTable[i] = NIL;
    }
}


CMyHashTable::~CMyHashTable()
{

}


void CMyHashTable::hashTablePrint()
{
    for (int i = 0; i < MAX_TABLE_SIZE; ++i)
    {
        cout << m_hashTable[i] << "  ";
    }
    cout << endl;
}


int CMyHashTable::hashAlgorithm(int value, int rank)
{
    int h1 = value % MAX_TABLE_SIZE;
    int h2 = 1 + (value % (MAX_TABLE_SIZE - 1));
    int h = (h1 + h2 * rank) % MAX_TABLE_SIZE;
    return h;
}


int CMyHashTable::hashSearch(int value)
{
    for (int i = 0; i < MAX_TABLE_SIZE; ++i)
    {
        int location = hashAlgorithm(value, i);
        if (m_hashTable[location] == value)
        {
            return location;
        }
        else if (m_hashTable[location] == NIL)
        {
            return NIL;
        }
    }
    return NIL;
}


void CMyHashTable::hashInsert(int value)
{
    for (int i = 0; i < MAX_TABLE_SIZE; ++i)
    {
        int location = hashAlgorithm(value, i);
        if (m_hashTable[location] == NIL || m_hashTable[location] == DELETE)
        {
            m_hashTable[location] = value;
            return;
        }
    }
    cerr << "hash table overflow" << endl;
}


int CMyHashTable::hashDelete(int value)
{
    int location = hashSearch(value);
    value = m_hashTable[location];
    m_hashTable[location] = DELETE;
    return value;
}


int main()
{
    cout << "Open Address HashTable" << endl;
    CMyHashTable myHashTable;
    for (int i = 100; i < 105; i++)
    {
        myHashTable.hashInsert(i);
    }

    myHashTable.hashTablePrint();

    int location = myHashTable.hashSearch(104);
    cout << location << endl;

    int value = myHashTable.hashDelete(101);

    myHashTable.hashTablePrint();
    return 0;
}
