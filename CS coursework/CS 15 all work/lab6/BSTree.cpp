/*
 * Implementation of BST (Binary Search Tree) class with integer keys
 * Data Structures BST lab
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>

#include "BSTree.h"

using namespace std;

//
// A couple handy functions for creating new, initialized nodes.
// We could make constructors for the struct, but let's keep things
// simple.
//

//
// Return a pointer to a newly allocated node initialized with given
// values.
//
BST::BSTNode* BST::newBSTNode(int v, BSTNode* left, BSTNode* right) {
    BST::BSTNode* newNode = new BSTNode;
    newNode->value        = v;
    newNode->left         = left;
    newNode->right        = right;

    return newNode;
}

//
// Return a pointer to a newly allocated leaf node with value v.
//
BST::BSTNode* BST::newBSTNode(int v) {
    return newBSTNode(v, nullptr, nullptr);
}

//
// Initialize an empty tree.
//
BST::BST() {
    root = nullptr;
}

//
// Delete all the nodes in the tree
//
BST::~BST() {
    postOrderDelete();
}

//
// isEmpty:
//     Return true if tree with given root is empty and false otherwise
//
bool BST::isEmpty(BSTNode* root) const {
    return root == nullptr;
}

//
// Insert: public version of Insert takes a value only and
//         inserts it into the tree at the root
//
void BST::unbalancedInsert(int v) {
    root = unbalancedInsert(root, v);
}

//
// Insert: (private version) inserts a value in the tree rooted at r
//
//   Return the root of current tree with the value inserted
//
//   note: ALWAYS adds a leaf.
//
//   Implementation notes:
//       - When the base case is reached, we are inserting the value
//         into an empty tree, i. e., r is nullptr.
//         In this case, we create a new leaf node with the given data
//         value and return a pointer to that.  If the caller had a
//         non-empty tree node, then they will set the corresponding
//         subtree in their node to the result.
//         DRAW THIS OUT!
//       - Duplicate keys will go into right branch here, i. e., the
//         left subtree contains values < node's key, right subtree
//         contains values >= node's key.
//
BST::BSTNode* BST::unbalancedInsert(BSTNode* r, int v) {
    if (r == nullptr) {
        return newBSTNode(v);
    } else if (v < r->value) {
        r->left = unbalancedInsert(r->left, v);
        return r;

    } else {
        r->right = unbalancedInsert(r->right, v);
        return r;
    }
}


//****************** inorder *****************//

//
// Perform an in-order print starting at the root of the entire tree
//
void BST::inOrder(std::ostream& out) const {
    inOrder(root, out); // calls the next one
    
}

//
// Perform an in-order print of the subtree rooted at the given node
//
void BST::inOrder(BSTNode* root, std::ostream& out) const {
    if (root != nullptr){
        inOrder(root->left, out);
        elems.push_back(root->value);
        inOrder(root->right, out);
        return;
    }
}


//****************** postorder *****************//

//
// Perform post-order traversal to delete the entire tree
//
void BST::postOrderDelete() {
    postOrderDelete(root);
}

//
// Perform post-order traversal to delete tree rooted at give node
// Question to ponder:  Could we use another traversal to delete the
//                      tree?
//
void BST::postOrderDelete(BSTNode* root) {
    // TODO: your code here
}


//****************** preorder *****************//

//
// Perform a pre-order print of the entire tree.
// Question to ponder:  Can we do this without a helper function?
//
void BST::preOrder(std::ostream& out) const {
    preOrder(root, out); // calls the next function (really needed?)
}

//
// Perform a pre-order print of the subtree rooted at given node.
// Uses a stack from the STL rather than the C++ run time stack.
//
void BST::preOrder(BSTNode* root, std::ostream& out) const {
    std::stack<BSTNode*> tree;
    tree.push(root);
    while (not tree.empty()){
        BSTNode* temp = tree.top();
        tree.pop();
        cout << temp->value << " ";
        if (temp->right != nullptr){
            tree.push(temp->right);
        }
        if (temp->left != nullptr){
            tree.push(temp->left);
        }
    }
}


//****************** levelorder *****************//

//
// Perform a level-order print of the entire tree
//
void BST::levelOrder(std::ostream& out) const {
    levelOrder(root, out);
}

//
// Perform a level-order print of the subtree rooted at the given node
// Uses a queue from the STL
//
void BST::levelOrder(BSTNode* root, std::ostream& out) const {

    std::queue<BSTNode*> queue;
    queue.push(root);
    BSTNode* curr;
    while (not queue.empty()){
        curr = queue.front();
        if (curr != nullptr){
            out << curr->value << " ";
            queue.push(curr->left);
            queue.push(curr->right);
        }
        queue.pop();
    }



}
