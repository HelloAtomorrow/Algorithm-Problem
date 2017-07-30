#include <iostream>
#include <stack>
#include <stdlib.h>
#include "binarySearchTree.h"
using namespace std;


CBinaryTree::CBinaryTree()
{
    p_root = NULL;
}


CBinaryTree::~CBinaryTree()
{
    while (p_root)
    {
        treeDelete(p_root);
    }
}


/*
*二叉树的中序遍历的迭代法实现，利用栈作为辅助数据结构。
*/
void CBinaryTree::inorderTreeWalk()
{
    STreeNode *p_node = p_root;
    stack<STreeNode*> walkStack;
    while (p_node || !walkStack.empty())
    {
        while (p_node)
        {
            walkStack.push(p_node);
            p_node = p_node->p_left;
        }
        p_node = walkStack.top();
        walkStack.pop();
        cout << "---" << p_node->value;
        p_node = p_node->p_right;
	}
	cout << endl;
}


STreeNode *CBinaryTree::treeSearch(int value)
{
    STreeNode *p_node = p_root;
    while (p_node && (value != p_node->value))
    {
        if (value < p_node->value)
        {
            p_node = p_node->p_left;
        }
        else
        {
            p_node = p_node->p_right;
        }
    }
    return p_node;
}


STreeNode *CBinaryTree::treeMinimum(STreeNode *p_node)
{
    while (p_node->p_left)
    {
        p_node = p_node->p_left;
    }
    return p_node;
}


STreeNode *CBinaryTree::treeMaxmum(STreeNode *p_node)
{
    while (p_node->p_right)
    {
        p_node = p_node->p_right;
    }
    return p_node;
}


STreeNode *CBinaryTree::treePredecessor(STreeNode *p_node)
{
    if (p_node == treeMinimum(p_root))
    {
        return p_node;
    }
    if (p_node->p_left)
    {
        return treeMaxmum(p_node->p_left);
    }
    STreeNode *p_temp = p_node->p_parent;
    while (p_temp && p_node == p_temp->p_left)
    {
        p_node = p_temp;
        p_temp = p_node->p_parent;
    }
    return p_temp;
}


STreeNode *CBinaryTree::treeSuccessor(STreeNode *p_node)
{
    if (p_node == treeMaxmum(p_root))
    {
        return p_node;
    }
    if (p_node->p_right)
    {
        return treeMinimum(p_node->p_right);
    }
    STreeNode *p_temp = p_node->p_parent;
    while (p_temp && p_node == p_temp->p_right)
    {
        p_node = p_temp;
        p_temp = p_node->p_parent;
    }
    return p_temp;
}


void CBinaryTree::treeInsert(STreeNode *p_insert)
{
    STreeNode *p_temp = NULL;
    STreeNode *p_node = p_root;
    while (p_node)
    {
        p_temp = p_node;
        if (p_insert->value < p_node->value)
        {
            p_node = p_node->p_left;
        }
        else
        {
            p_node = p_node->p_right;
        }
    }
    p_insert->p_parent = p_temp;
    if (!p_temp)
    {
        p_root = p_insert;
    }
    else if (p_insert->value < p_temp->value)
    {
        p_temp->p_left = p_insert;
    }
    else
    {
        p_temp->p_right = p_insert;
    }
}


/*
二叉搜索树的节点删除操作：分为3种情况考虑：
1、需要删除的节点没有左儿子，直接用右儿子的子树代替被删除的节点。
2、需要删除的节点没有右儿子，直接用左儿子的子树代替被删除的节点。
3、找到需要删除节点右儿子（子树）的最小节点，这个最小节点是一定没有左儿子的，于是用这个最小节点的右儿子代替这个最小节点，然后用最小节点代替被删除的节点。
*/
int CBinaryTree::treeDelete(STreeNode *p_delete)
{
    if (!p_delete->p_left)
    {
        transPlant(p_delete, p_delete->p_right);
    }
    else if (!p_delete->p_right)
    {
        transPlant(p_delete, p_delete->p_left);
    }
    else
    {
        STreeNode *p_temp = treeMinimum(p_delete->p_right);
        if (p_temp->p_parent != p_delete)
        {
            transPlant(p_temp, p_temp->p_right);
            p_temp->p_right = p_delete->p_right;
            p_temp->p_right->p_parent = p_temp;
        }
        transPlant(p_delete, p_temp);
        p_temp->p_left = p_delete->p_left;
        p_temp->p_left->p_parent = p_temp;
    }
    delete p_delete;
}


void CBinaryTree::transPlant(STreeNode *p_sourceNode, STreeNode *p_replaceNode)
{
    if (!p_sourceNode->p_parent)
    {
        p_root = p_replaceNode;
    }
    else if (p_sourceNode == p_sourceNode->p_parent->p_left)
    {
        p_sourceNode->p_parent->p_left = p_replaceNode;
    }
    else
    {
        p_sourceNode->p_parent->p_right = p_replaceNode;
    }
    if (p_replaceNode)
    {
        p_replaceNode->p_parent = p_sourceNode->p_parent;
    }
}


int main()
{
    cout << "binarySearchTree" << endl;
    CBinaryTree myBinaryTree;
    cout << "input random number: ";
    for (int i = 0; i < 5; ++i)
    {
        int randNum = rand() % 5;
        cout << "---" << randNum;
        STreeNode *p_node = new STreeNode;
        p_node->value = randNum;
        myBinaryTree.treeInsert(p_node);
    }
    cout << endl;
    cout << "inorderTreeWalk: ";
    myBinaryTree.inorderTreeWalk();	

    STreeNode *p_search = myBinaryTree.treeSearch(2);
    cout << "search number: " << p_search->value << endl;

    STreeNode *p_miniNode = myBinaryTree.treeMinimum(myBinaryTree.p_root);
    cout << "mini number: " << p_miniNode->value << endl;

    STreeNode *p_maxNode = myBinaryTree.treeMaxmum(myBinaryTree.p_root);
    cout << "max number: " << p_maxNode->value << endl;

    cout << "root number: " << myBinaryTree.p_root->value << endl;
    STreeNode *p_predecessor = myBinaryTree.treePredecessor(myBinaryTree.p_root);
    cout << "root predecessor: " << p_predecessor->value << endl;

    STreeNode *p_suecessor = myBinaryTree.treeSuccessor(myBinaryTree.p_root);
    cout << "root p_suecessor: " << p_suecessor->value << endl;

    while (myBinaryTree.p_root)
    {
        myBinaryTree.treeDelete(myBinaryTree.p_root);
    }
    cout << "inorderTreeWalk: ";
    myBinaryTree.inorderTreeWalk();
    return 0;
}
