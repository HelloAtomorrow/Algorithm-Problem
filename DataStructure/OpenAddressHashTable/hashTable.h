/*
hash table的开放寻址法实现：
通过hash探查算法找到hash表中的位置，
进行添加，删除，打印等操作。
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

const int NIL = -10000;
const int DELETE = -9999;
const int MAX_TABLE_SIZE = 7;


class CMyHashTable
{
public:
    CMyHashTable();
    ~CMyHashTable();

    void hashTablePrint();
    int hashAlgorithm(int value, int rank);
    int hashSearch(int value);
    void hashInsert(int value);
    int hashDelete(int value);

private:
    int m_hashTable[MAX_TABLE_SIZE];
};
#endif
