/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;


/*
 * name: Constructor for empty list
 * purpose: Creates an empty tree
 * arguments: None
 * returns: None
 */
BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}

/*
 * name: Deconstructor
 * purpose: Clears all heap allocated memory
 * arguments: None
 * returns: None
 */
BinarySearchTree::~BinarySearchTree(){
    // walk tree in post-order traversal and delete
    post_order_delete(root);
    root = nullptr; 
}

/*
 * name: post_order_delete
 * purpose: Deletes all nodes
 * arguments: Current node
 * returns: None
 */
void BinarySearchTree::post_order_delete(Node *node){
    if (node == nullptr){
        return;
    }
    post_order_delete(node->left);
    post_order_delete(node->right);
    delete node;
}

/*
 * name: Copy Constructor
 * purpose: Initializes a tree identical to input tree
 * arguments: The tree being copied
 * returns: None
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source){
    root = pre_order_copy(source.root);
}

/*
 * name: Overloaded assignment operator
 * purpose: Overloads assignment operator
 * arguments: The tree being assigned
 * returns: The pointer for the tree
 */
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source){
    if (&source == this){
        return *this;
    }
    if (root != nullptr){
        post_order_delete(root);
    }
    root = nullptr;
    this->root = pre_order_copy(source.root);    
    return *this;
}

//pre order copy
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const{
    if (node == nullptr){
        return nullptr;
    }
    Node* temp = new Node;
    temp->count = node->count; //creates a new node, new_node() doesn't work
    temp->data = node->data;
    temp->left = nullptr;
    temp->right = nullptr;

    if (node->left != nullptr){
        temp->left = pre_order_copy(node->left);
    }
    if (node->right != nullptr){
        temp->right = pre_order_copy(node->right);
    }
    return temp;
}

/*
 * name: find_min()
 * purpose: Wrapper function for private find_min()
 * arguments: None
 * returns: Min if it exists, INT_MAX otherwise
 */
int BinarySearchTree::find_min() const{
    if (root == nullptr)
        return numeric_limits<int>::max(); // INT_MAX
    return find_min(root)->data;
}

/*
 * name: find_min(Node *node)
 * purpose: Private helper to find the minimum
 * arguments: Current node
 * returns: The node that contains the minimum if it exists
 */
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const{
    if (node == nullptr){
        return root;
    } 
    if (node->left == nullptr){
        return node;
    }
    return find_min(node->left);
}

/*
 * name: find_max()
 * purpose: Wrapper to find max value
 * arguments: None
 * returns: Value of the max node if it exists, INT_MIN otherwise
 */
int BinarySearchTree::find_max() const{
    if (root == nullptr)
        return numeric_limits<int>::min(); // INT_MIN
    return find_max(root)->data;
}

/*
 * name: find_max(Node *node)
 * purpose: Private helper to find the maximum
 * arguments: Current node
 * returns: The node that contains the maximum if it exists
 */
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const{
    if (node == nullptr){
        return root;
    } 
    if (node->right == nullptr){
        return node;
    }
    return find_max(node->right);
}

/*
 * name: contains(int value)
 * purpose: Wrapper function for private helper contains()
 * arguments: Value being searched for
 * returns: True if in BST, false otherwise
 */
bool BinarySearchTree::contains(int value) const{
    return contains(root, value);
}

/*
 * name: contains(Node *node, int value)
 * purpose: Private recursive helper to check if a value is in the BST
 * arguments: The current node, and value being searched for
 * returns: True if value is in BST, false otherwise
 */
bool BinarySearchTree::contains(Node *node, int value) const{
    if (node == nullptr){
        return false;
    }
    if (value == node->data){ //if at value
        return true;
    }

    //Utilize BST invariant to find the node
    if (value < node->data){ //go to left
        return contains(node->left, value);
    }
    if (value > node->data){ //go to right
        return contains(node->right, value);
    }
    return false;
}

/*
 * name: contains(Node *node, int value)
 * purpose: Private recursive helper to find Node in BST
 * arguments: The current node, and value of node being searched for
 * returns: Returns the node if value exists, nullptr otherwise
 */
BinarySearchTree::Node* BinarySearchTree::contains_node(Node *node, int value){
    if (node == nullptr){
        return nullptr;
    }
    if (value == node->data){ //if at node
        return node;
    }

    //Utilize BST invariant to find the node
    if (value < node->data){
        return contains_node(node->left, value);
    } else {
        return contains_node(node->right, value);
    }
}
 
/*
 * name: insert(int value)
 * purpose: Public wrapper for inserting
 * arguments: The current node, and value being searched for
 * returns: True if value is in BST, false otherwise
 */
void BinarySearchTree::insert(int value){
    insert(root, nullptr, value);
}

/*
 * name: insert(Node *node, Node *parent, int value)
 * purpose: Private helper for inserting a Node
 * arguments: Current node, parent of current node, and value being inserted
 * returns: None
 */
void BinarySearchTree::insert(Node *node, Node *parent, int value){
    if (node == nullptr){
        Node* temp = new_Node(value, nullptr, nullptr);
        if (parent == nullptr){ //performs insertion
            root = temp;
        } else if (value < parent->data){
            parent->left = temp;
        } else {
            parent->right = temp;
        }
        return;
    }
    if (value == node->data){ //if duplicate node
        node->count++;
    } else if (value < node->data){ //go to left
        insert(node->left, node, value); 
    } else if (value > node->data){ //go to right
        insert(node->right, node, value);
    }
    return;
}

/*
 * name: remove(int value)
 * purpose: Public wrapper for int value
 * arguments: Value being removed from tree
 * returns: True if node removed, false otherwise
 */
bool BinarySearchTree::remove(int value){
    return remove(root, nullptr, value);
}

/*
 * name: remove(Node *node, Node *parent, int value)
 * purpose: Private helper for removing a node
 * arguments: Current node, parent of current node, and value being removed
 * returns: True if node removed, false otherwise
 * Explanation: There are three main cases when removal is performed: node is 
 * leaf, has 1 child, or 2 children. All edge cases are explained in the
 * respective helper functions. 
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value){
    if (node == nullptr){ //If reached, then node not in tree
        return false;
    }
    if (node->data == value){
        if (node->count > 1){ //if node has count greater than 1
            node->count--;
        } else if (node->left == nullptr and node->right == nullptr){
            remove_leaf(node, parent); //means removing a leaf
        } else if (node->left != nullptr and node->right != nullptr){
            remove_two_child(node, parent);
        } else {
            remove_one_child(node, parent); //removing node with 1 child
        }
        return true;
    } else if (value < node->data){ //go to left to find node
        return remove(node->left, node, value);
    } else { //go to right to find node
        return remove(node->right, node, value);
    }
}

/*
 * name: remove_leaf(Node *node, Node *parent)
 * purpose: Private helper that removes a leaf
 * arguments: The current node and it's parent
 * returns: None
 */
void BinarySearchTree::remove_leaf(Node *node, Node *parent){
    //handles root and nonroot nodes slightly differently
    if (parent != nullptr){ //if parent == nullptr, at root
        if (parent->left == node){ //reassign parent
            parent->left = nullptr; 
        } else {
            parent->right = nullptr;
        }
    } else { //if at root
        root = nullptr;
    }
    delete node;
    node = nullptr;
}

/*
 * name: remove_one_child(Node *node, Node *parent)
 * purpose: Helper function for removing a node when it has one child
 * arguments: Current node and it's parent
 * returns: None
 */
void BinarySearchTree::remove_one_child(Node *node, Node *parent){
    //since if at root, parent == nullptr, handle root and nonroot slightly
    //differently.
    if (parent == nullptr){ //If at root
        if (node->left == nullptr){ //child is right child
            root = node->right;
        } else {
            root = node->left; //child is right child
        }
    } else { //If not at root
        if (parent->left != nullptr){ //if left is child 
            if (node->left != nullptr){ //child of removed has 2 options
                parent->left = node->left; 
            } else {
                parent->left = node->right;
            }
        } else { //if right is child
            if (node->left != nullptr){
                parent->right = node->left;
            } else {
                parent->right = node->right;
            }
        }
    }
    delete node;
}

/*
 * name: remove_two_child(Node *node, Node *parent)
 * purpose: Helper function for removing a node when it has two children
 * arguments: Node being removed and it's parent
 * returns: None
 */
void BinarySearchTree::remove_two_child(Node *node, Node *parent){
    Node *temp = find_min(node->right); //temp replaces node
    //Again, handles root and nonroot differently due to prescense of parent
    //nodes.
    if (parent == nullptr){ //node == root
        if (temp->left == nullptr and temp->right == nullptr){ //if temp = leaf
            node->count = temp->count;
            node->data = temp->data;
            remove_leaf(temp, find_parent(root, temp));
        } else {
            node->count = temp->count; 
            node->data = temp->data;
            remove_one_child(node->right, node);
        }
    } else { //node != root
        Node *temp_par = find_parent(root, temp);
        if (temp->left == nullptr and temp->right == nullptr){ //if temp = leaf
            node->count = temp->count;
            node->data = temp->data;
            remove_leaf(temp, temp_par); //we now just need to remove leaf
        } else { //if temp has 1 child, can't use remove_one_child()
            node->count = temp->count; //updates node being removed
            node->data = temp->data;
            if (temp_par->left == temp){ 
                temp_par->left = temp->right;
            } else {
                temp_par->right = temp->right;
            }
            delete temp;
        }
    }
}

/*
 * name: tree_height()
 * purpose: Wrapper for finding height of tree
 * arguments: None
 * returns: Height of tree
 */
int BinarySearchTree::tree_height() const{
    return tree_height(root);
}

/*
 * name: tree_height()
 * purpose: Finds height of tree
 * arguments: Current node
 * returns: Height of tree
 */
int BinarySearchTree::tree_height(Node *node) const{
    if (node == nullptr){ //if at end
        return -1;
    }
    return 1 + max(tree_height(node->left), tree_height(node->right));
}

// returns the total number of nodes
int BinarySearchTree::node_count() const{
    return node_count(root);
}

/*
 * name: node_count(Node *node)
 * purpose: Private helper for inserting a Node
 * arguments: Current node, parent of current node, and value being inserted
 * returns: None
 */
int BinarySearchTree::node_count(Node *node) const{
    if (node == nullptr){
        return 0;
    }
    return 1 + node_count(node->left) + node_count(node->right);
}

//return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const{
    return count_total(root);
}

/*
 * name: count_total(Node *node)
 * purpose: Sums up all values, including duplicates
 * arguments: Current node
 * returns: The total sum
 */
int BinarySearchTree::count_total(Node *node) const{
    if (node == nullptr){
        return 0;
    }
    return node->count*node->data + count_total(node->left) + 
                                    count_total(node->right);
}

/*
 * name: new_Node()
 * purpose: Create a new node
 * arguments: Value of node, along with it's left and right pointers
 * returns: The node
 */
BinarySearchTree::Node *BinarySearchTree::new_Node(int value, Node *left, 
                                                        Node *right){
    BinarySearchTree::Node* newNode = new Node;
    newNode->data    = value;
    newNode->left    = left;
    newNode->right   = right;
    newNode->count   = 1;

    return newNode;
}

BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}
