/*
栈的实现方法：
先定义栈的节点数据结构，使用指针将其保存为单向链表的方式。
*/

#include <iostream>
using namespace std;

template <class T>
struct SStackNode
/*栈的节点结构*/
{
    T value;
    SStackNode *next;
};


template <class T>
class CMyStack
{
/*栈的类的实现，包括压栈，弹栈，判断栈是否为空的操作
top指向栈顶元素*/
public:
    CMyStack();
    ~CMyStack();
    bool isEmpty();
    void push(T value);
    T pop();
    T stackTop();

private:
    SStackNode<T> *top;   
};


template <class T>
CMyStack<T>::CMyStack()
{
    top = NULL;
}


template <class T>
CMyStack<T>::~CMyStack()
{
    SStackNode<T> *node = NULL;
    while (top != NULL)
    {
        node = top;
        top = top->next;
        delete node;
    }
}


template <class T>
void CMyStack<T>::push(T value)
{
    SStackNode<T> *node = new SStackNode<T>;
    node->value = value;
    node->next = top;
    top = node;
}


template <class T>
T CMyStack<T>::pop()
{
    SStackNode<T> *node = top;
    T value = node->value;
    top = top->next;
    delete node;
    return value;
}


template <class T>
bool CMyStack<T>::isEmpty()
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
