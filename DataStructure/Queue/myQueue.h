/*
用数组实现一个循环队列，包括队列的入队、
出队、判断队列是否已满、是否为空。
*/

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