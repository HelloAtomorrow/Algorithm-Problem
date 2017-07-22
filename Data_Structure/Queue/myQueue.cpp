/*
用数组实现一个循环队列，包括队列的入队、
出队、判断队列是否已满、是否为空。
*/

#include <iostream>
using namespace std;


const  int MAX_QUEUE_SIZE = 10;


template <typename elemType>
class CMyQueue
{
public:
    CMyQueue();
    ~CMyQueue();
    bool isEmpty();
    bool isFull();
    bool enqueue(elemType value);
    elemType dequeue();
    
private:
    elemType queue[MAX_QUEUE_SIZE];
    int head;
    int tail;
};


template <typename elemType>
CMyQueue<elemType>::CMyQueue()
{
    head = 0;
    tail = 0;
}


template <typename elemType>
CMyQueue<elemType>::~CMyQueue()
{

}


template <typename elemType>
bool CMyQueue<elemType>::isEmpty()
{
    return head == tail;
}


template <typename elemType>
bool CMyQueue<elemType>::isFull()
{
    return ((tail + 1) % MAX_QUEUE_SIZE) == head;
}


template <typename elemType>
bool CMyQueue<elemType>::enqueue(elemType value)
{
    if (!isFull())
    {
        cout << value << endl;
        queue[tail] = value;
        tail = (tail + 1) % MAX_QUEUE_SIZE;
        return true;
    }
    else
        return false;
}


template <typename elemType>
elemType CMyQueue<elemType>::dequeue()
{
    if (!isEmpty())
    {
        elemType value = queue[head];
        cout << value << endl;
        head = (head + 1) % MAX_QUEUE_SIZE;
        return value;
    }
}


int main()
{
    CMyQueue<int> q;
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    for (int i = 0; i < 5; i++)
    {
        q.enqueue(i);
    }
    for (int i = 0; i < 3; i++)
    {
        q.dequeue();
    }
    for (int i = 0; i < 7; i++)
    {
        q.enqueue(i);
    }
    for (int i = 0; i < 9; i++)
    {
        q.dequeue();
    }
    return 0;
}
