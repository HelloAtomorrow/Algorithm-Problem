/*
红黑树：
红黑树是一种特殊的二叉搜索树，红黑树中没有任何一条路径会比其他路径长出两倍。
红黑树的插入和删除操作比较复杂，需要左旋，右旋，以及变色等函数来保证红黑树的节点颜色。
*/


#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <string>


struct SRedBlackTreeNode
{
    int value;
    std::string color;
    SRedBlackTreeNode *p_parent = NULL;
    SRedBlackTreeNode *p_left = NULL;
    SRedBlackTreeNode *p_right = NULL;
};


class CRedBLackTree
{
public:
    CRedBLackTree();
    ~CRedBLackTree(); 
    void inorderTreeWalk();
    SRedBlackTreeNode *treeSearch(int value);
    SRedBlackTreeNode *treeMinimum(SRedBlackTreeNode *p_node);
    SRedBlackTreeNode *treeMaxmum(SRedBlackTreeNode *p_node);
    SRedBlackTreeNode *treePredecessor(SRedBlackTreeNode *p_node);
    SRedBlackTreeNode *treeSuccessor(SRedBlackTreeNode *p_node);
    void treeInsert(SRedBlackTreeNode *p_insert);
    int treeDelete(SRedBlackTreeNode *p_delete);

    SRedBlackTreeNode *p_root;
    SRedBlackTreeNode *p_nil;    

private:
    void transPlant(SRedBlackTreeNode *p_sourceNode, SRedBlackTreeNode *p_replaceNode);
    void leftRotate(SRedBlackTreeNode *p_node);
    void rightRotate(SRedBlackTreeNode *p_node);
    void insertFixup(SRedBlackTreeNode *p_insert);
    void deleteFixup(SRedBlackTreeNode *p_node);

};
#endif
