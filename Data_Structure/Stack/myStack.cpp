/*
栈的实现方法：
先定义栈的节点数据结构，使用指针将其保存为单向链表的方式。
*/

#include <iostream>
using namespace std;

template <typename elemType>
struct SStackNode
/*栈的节点结构*/
{
    elemType value;
    SStackNode *next;
};


template <typename elemType>
class CMyStack
{
/*栈的类的实现，包括压栈，弹栈，判断栈是否为空的操作
top指向栈顶元素*/
public:
    CMyStack();
    ~CMyStack();
    bool isEmpty();
    void push(elemType value);
    elemType pop();
    elemType stackTop();

private:
    SStackNode<elemType> *top;   
};


template <typename elemType>
CMyStack<elemType>::CMyStack()
{
    top = NULL;
}


template <typename elemType>
CMyStack<elemType>::~CMyStack()
{
    SStackNode<elemType> *node = NULL;
    while (top != NULL)
    {
        node = top;
        top = top->next;
        delete node;
    }
}


template <typename elemType>
void CMyStack<elemType>::push(elemType value)
{
    SStackNode<elemType> *node = new SStackNode<elemType>;
    node->value = value;
    node->next = top;
    top = node;
}


template <typename elemType>
elemType CMyStack<elemType>::pop()
{
    SStackNode<elemType> *node = top;
    elemType value = node->value;
    top = top->next;
    delete node;
    return value;
}


template <typename elemType>
bool CMyStack<elemType>::isEmpty()
{
    if (top == NULL)
    {
    	return true;
    }
    else
    {
    	return false;
    }
}


int main()
{
    cout << "stack" << endl;
    CMyStack<int> s;
    cout << s.isEmpty() << endl;
    for (int i = 0; i < 10; i++)
    {
    	cout << i << endl;
    	s.push(i);
    }
    while (!s.isEmpty())
    {
    	int value = s.pop();
    	cout << value << endl;
    }
    return 0;
}
