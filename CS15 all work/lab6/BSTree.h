#ifndef BSTREE_H
#define BSTREE_H
/*
 * Class for a binary search tree (BST) with integer keys
 * for Data Structures (BST) lab
 */
#include <iostream>
#include <vector>
using namespace std;
class BST {
    public:
    BST();
    ~BST();

    void unbalancedInsert(int v);

    void inOrder(std::ostream& out) const;
    void preOrder(std::ostream& out) const;
    void levelOrder(std::ostream& out) const;

    void postOrderDelete();

    private:
    struct BSTNode {
        int      value;
        BSTNode* left;
        BSTNode* right;
    };
    BSTNode* root;

    BSTNode* newBSTNode(int v);
    BSTNode* newBSTNode(int v, BSTNode* left, BSTNode* right);

    bool     isEmpty(BSTNode* root) const;
    BSTNode* unbalancedInsert(BSTNode* root, int v);
    void     inOrder(BSTNode* root, std::ostream& out) const;
    void     preOrder(BSTNode* root, std::ostream& out) const;
    void     levelOrder(BSTNode* root, std::ostream& out) const;
    void     postOrderDelete(BSTNode* root);
    std::vector<int> elems;

};

#endif
