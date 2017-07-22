#include <iostream>
#include "myStack.h"
using namespace std;


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
