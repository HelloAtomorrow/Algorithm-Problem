/*
栈的实现方法：
先定义栈的节点数据结构，使用指针将其保存为单向链表的方式。
*/

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