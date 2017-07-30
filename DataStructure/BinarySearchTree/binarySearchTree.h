/*
二叉搜索树：
实现了二叉搜索树的中序遍历，查找给定值的节点，查找最小节点，查找最大节点，
查找前驱节点，查找后继节点，插入节点，删除节点等操作。
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


struct STreeNode
{
    int value;
    STreeNode *p_parent = NULL;
    STreeNode *p_left = NULL;
    STreeNode *p_right = NULL;
};


class CBinaryTree
{
public:
    CBinaryTree();
    ~CBinaryTree();	
    void inorderTreeWalk();
    STreeNode *treeSearch(int value);
    STreeNode *treeMinimum(STreeNode *p_node);
    STreeNode *treeMaxmum(STreeNode *p_node);
    STreeNode *treePredecessor(STreeNode *p_node);
    STreeNode *treeSuccessor(STreeNode *p_node);
    void treeInsert(STreeNode *p_insert);
    int treeDelete(STreeNode *p_delete);

    STreeNode *p_root;

private:
    void transPlant(STreeNode *p_sourceNode, STreeNode *p_replaceNode);
};
#endif
	
