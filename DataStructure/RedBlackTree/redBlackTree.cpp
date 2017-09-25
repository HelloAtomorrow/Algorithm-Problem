#include <iostream>
#include <stack>
#include <stdlib.h>
#include "RedBlackTree.h"
using namespace std;


CRedBLackTree::CRedBLackTree()
{    
    p_nil = new SRedBlackTreeNode;
    p_nil->color = "black";
    p_root = p_nil;
}


CRedBLackTree::~CRedBLackTree()
{
    while (p_root != p_nil)
    {
        treeDelete(p_root);
    }
    delete p_nil;
}


void CRedBLackTree::inorderTreeWalk()
{
    SRedBlackTreeNode *p_node = p_root;
    stack<SRedBlackTreeNode*> walkStack;
    while ((p_node != p_nil) || (!walkStack.empty()))
    {
        while (p_node != p_nil)
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


SRedBlackTreeNode *CRedBLackTree::treeSearch(int value)
{
    SRedBlackTreeNode *p_node = p_root;
    while ((p_node != p_nil) && (value != p_node->value))
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


SRedBlackTreeNode *CRedBLackTree::treeMinimum(SRedBlackTreeNode *p_node)
{
    while (p_node->p_left != p_nil)
    {
        p_node = p_node->p_left;
    }
    return p_node;
}


SRedBlackTreeNode *CRedBLackTree::treeMaxmum(SRedBlackTreeNode *p_node)
{
    while (p_node->p_right != p_nil)
    {
        p_node = p_node->p_right;
    }
    return p_node;
}


SRedBlackTreeNode *CRedBLackTree::treePredecessor(SRedBlackTreeNode *p_node)
{
    if (p_node == treeMinimum(p_root))
    {
        return p_node;
    }
    if (p_node->p_left != p_nil)
    {
        return treeMaxmum(p_node->p_left);
    }
    SRedBlackTreeNode *p_temp = p_node->p_parent;
    while (p_temp != p_nil && p_node == p_temp->p_left)
    {
        p_node = p_temp;
        p_temp = p_node->p_parent;
    }
    return p_temp;
}


SRedBlackTreeNode *CRedBLackTree::treeSuccessor(SRedBlackTreeNode *p_node)
{
    if (p_node == treeMaxmum(p_root))
    {
        return p_node;
    }
    if (p_node->p_right != p_nil)
    {
        return treeMinimum(p_node->p_right);
    }
    SRedBlackTreeNode *p_temp = p_node->p_parent;
    while (p_temp != p_nil && p_node == p_temp->p_right)
    {
        p_node = p_temp;
        p_temp = p_node->p_parent;
    }
    return p_temp;
}


void CRedBLackTree::leftRotate(SRedBlackTreeNode *p_node)
{
    SRedBlackTreeNode *p_nodeRight = p_node->p_right;
    p_node->p_right = p_nodeRight->p_left;
    if (p_nodeRight->p_left != p_nil)
    {
        p_nodeRight->p_left->p_parent = p_node;
    }
    if (p_node->p_parent == p_nil)
    {
        p_root = p_nodeRight;
        p_root->p_parent = p_nil;
    }
    else if (p_node == p_node->p_parent->p_left)
    {
        p_node->p_parent->p_left = p_nodeRight;
    }
    else
    {
        p_node->p_parent->p_right = p_nodeRight;
    }
    p_nodeRight->p_parent = p_node->p_parent;
    p_nodeRight->p_left = p_node;
    p_node->p_parent = p_nodeRight;
}


void CRedBLackTree::rightRotate(SRedBlackTreeNode *p_node)
{
    SRedBlackTreeNode *p_nodeLeft = p_node->p_left;
    p_node->p_left = p_nodeLeft->p_right;
    if (p_nodeLeft->p_right != p_nil)
    {
        p_nodeLeft->p_right->p_parent = p_node;
    }
    if (p_node->p_parent == p_nil)
    {
        p_root = p_nodeLeft;
        p_root->p_parent = p_nil;
    }
    else if (p_node == p_node->p_parent->p_left)
    {
        p_node->p_parent->p_left = p_nodeLeft;
    }
    else
    {
        p_node->p_parent->p_right = p_nodeLeft;
    }
    p_nodeLeft->p_parent = p_node->p_parent;
    p_nodeLeft->p_right = p_node;
    p_node->p_parent = p_nodeLeft;
}


void CRedBLackTree::treeInsert(SRedBlackTreeNode *p_insert)
{
    SRedBlackTreeNode *p_temp = p_nil;
    SRedBlackTreeNode *p_node = p_root;
    while (p_node != p_nil)
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
    if (p_temp == p_nil)
    {
        p_root = p_insert;
        p_root->p_parent = p_nil;
    }
    else if (p_insert->value < p_temp->value)
    {
        p_temp->p_left = p_insert;
    }
    else
    {
        p_temp->p_right = p_insert;
    }
    p_insert->p_left = p_nil;
    p_insert->p_right = p_nil;
    p_insert->color = "red";
    insertFixup(p_insert);
}


void CRedBLackTree::insertFixup(SRedBlackTreeNode *p_fixup)
{
    while (p_fixup->p_parent->color == "red")
    {
        if (p_fixup->p_parent == p_fixup->p_parent->p_parent->p_left)
        {
            SRedBlackTreeNode *p_uncle = p_fixup->p_parent->p_parent->p_right;
            if (p_uncle->color == "red")
            {
                p_fixup->p_parent->color = "black";
                p_uncle->color = "black";
                p_fixup->p_parent->p_parent->color = "red";
                p_fixup = p_fixup->p_parent->p_parent;
                continue;
            }
            else if (p_fixup == p_fixup->p_parent->p_right)
            {
                p_fixup = p_fixup->p_parent;
                leftRotate(p_fixup);
            }
            p_fixup->p_parent->color = "black";
            p_fixup->p_parent->p_parent->color = "red";
            rightRotate(p_fixup->p_parent->p_parent);        
        }
        else
        {
            SRedBlackTreeNode *p_uncle = p_fixup->p_parent->p_parent->p_left;
            if (p_uncle->color == "red")
            {
                p_fixup->p_parent->color = "black";
                p_uncle->color = "black";
                p_fixup->p_parent->p_parent->color = "red";
                p_fixup = p_fixup->p_parent->p_parent;
            }
            else if (p_fixup == p_fixup->p_parent->p_left)
            {
                p_fixup = p_fixup->p_parent;
                rightRotate(p_fixup);
            }
            p_fixup->p_parent->color = "black";
            p_fixup->p_parent->p_parent->color = "red";
            leftRotate(p_fixup->p_parent->p_parent); 
        }
    }
    p_root->color = "black";
}


int CRedBLackTree::treeDelete(SRedBlackTreeNode *p_delete)
{
    SRedBlackTreeNode *p_temp1 = p_delete;
    std::string originColor = p_temp1->color;
    SRedBlackTreeNode *p_temp2;
    if (p_delete->p_left == p_nil)
    {
        p_temp2 = p_delete->p_right;
        transPlant(p_delete, p_delete->p_right);
    }
    else if (p_delete->p_right == p_nil)
    {
        p_temp2 = p_delete->p_left;
        transPlant(p_delete, p_delete->p_left);
    }
    else
    {
        p_temp1 = treeMinimum(p_delete->p_right);
        originColor = p_temp1->color;
        p_temp2 = p_temp1->p_right;
        if (p_temp1->p_parent == p_delete)
        {
            p_temp2->p_parent = p_temp1; 
        }
        if (p_temp1->p_parent != p_delete)
        {
            transPlant(p_temp1, p_temp1->p_right);
            p_temp1->p_right = p_delete->p_right;
            p_temp1->p_right->p_parent = p_temp1;
        }
        transPlant(p_delete, p_temp1);
        p_temp1->p_left = p_delete->p_left;
        p_temp1->p_left->p_parent = p_temp1;
        p_temp1->color = p_delete->color;
    }
    delete p_delete;
    if (originColor == "black")
    {
        deleteFixup(p_temp2);
    }
}


void CRedBLackTree::deleteFixup(SRedBlackTreeNode *p_node)
{
    SRedBlackTreeNode *p_brother;
    while ((p_node != p_root) && (p_node->color == "black"))
    {
        if (p_node == p_node->p_parent->p_left)
        {
            p_brother = p_node->p_parent->p_right;
            if (p_brother->color == "red")
            {
                p_brother->color = "black";
                p_node->p_parent->color = "red";
                leftRotate(p_node->p_parent);
                p_brother = p_node->p_parent->p_right;
            }
            if ((p_brother->p_left->color == "black") && (p_brother->p_right->color == "black"))
            {
                p_brother->color = "red";
                p_node = p_node->p_parent;
                continue;
            }
            else if (p_brother->p_right->color == "black")
            {
                p_brother->p_left->color = "black";
                p_brother->color = "red";
                rightRotate(p_brother);
                p_brother = p_node->p_parent->p_right;
            }
            p_brother->color = p_node->p_parent->color;
            p_node->p_parent->color = "black";
            p_brother->p_right->color = "black";
            leftRotate(p_node->p_parent);
            p_node = p_root;
        }
        else
        {
            p_brother = p_node->p_parent->p_left;
            if (p_brother->color == "red")
            {
                p_brother->color = "black";
                p_node->p_parent->color = "red";
                rightRotate(p_node->p_parent);
                p_brother = p_node->p_parent->p_left;
            }
            if ((p_brother->p_left->color == "black") && (p_brother->p_right->color == "black"))
            {
                p_brother->color = "red";
                p_node = p_node->p_parent;
                continue;
            }
            else if (p_brother->p_left->color == "black")
            {
                p_brother->p_right->color = "black";
                p_brother->color = "red";
                leftRotate(p_brother);
                p_brother = p_node->p_parent->p_left;
            }
            p_brother->color = p_node->p_parent->color;
            p_node->p_parent->color = "black";
            p_brother->p_left->color = "black";
            rightRotate(p_node->p_parent);
            p_node = p_root;
        }
    }
    p_node->color = "black";
}


void CRedBLackTree::transPlant(SRedBlackTreeNode *p_sourceNode, SRedBlackTreeNode *p_replaceNode)
{
    if (p_sourceNode->p_parent == p_nil)
    {
        p_root = p_replaceNode;
        p_root->p_parent = p_nil;
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
    cout << "RedBlackTree" << endl;
    CRedBLackTree myRedBlackTree;
    cout << "input random number: ";
    for (int i = 0; i < 5; ++i)
    {
        int randNum = rand() % 5;
        cout << "---" << randNum;
        SRedBlackTreeNode *p_node = new SRedBlackTreeNode;
        p_node->value = randNum;
        cout << randNum << endl;
        myRedBlackTree.treeInsert(p_node);
    }
    cout << endl;
    cout << "inorderTreeWalk: ";
    myRedBlackTree.inorderTreeWalk(); 

    SRedBlackTreeNode *p_search = myRedBlackTree.treeSearch(2);
    cout << "search number: " << p_search->value << endl;

    SRedBlackTreeNode *p_miniNode = myRedBlackTree.treeMinimum(myRedBlackTree.p_root);
    cout << "mini number: " << p_miniNode->value << endl;

    SRedBlackTreeNode *p_maxNode = myRedBlackTree.treeMaxmum(myRedBlackTree.p_root);
    cout << "max number: " << p_maxNode->value << endl;

    cout << "root number: " << myRedBlackTree.p_root->value << endl;
    SRedBlackTreeNode *p_predecessor = myRedBlackTree.treePredecessor(myRedBlackTree.p_root);
    cout << "root p_redecessor: " << p_predecessor->value << endl;

    SRedBlackTreeNode *p_suecessor = myRedBlackTree.treeSuccessor(myRedBlackTree.p_root);
    cout << "root p_suecessor: " << p_suecessor->value << endl;

    while (myRedBlackTree.p_root != myRedBlackTree.p_nil)
    {
        myRedBlackTree.treeDelete(myRedBlackTree.p_root);
        myRedBlackTree.inorderTreeWalk();
    }
    cout << "inorderTreeWalk: ";
    myRedBlackTree.inorderTreeWalk();
    return 0;
}