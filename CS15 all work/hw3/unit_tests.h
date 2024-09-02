/*
 *  unit_tests.h
 *  Scott Fullenbaum
 *  3/29/2022
 *
 *  CS 15 HW 3 BST
 *
 *  Tests for BST
 *
 */

#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>

using namespace std;

//tests inserting into empty tree
void insert_empty_test(){
    BinarySearchTree BST;
    BST.insert(5);
    assert(BST.find_min() == 5);
}

//tests inserting when node of insertion has no children
void insert_nochild_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    assert(BST.find_min() == 4);
}

//tests inserting when parent of new node already has one child
void insert_onechild_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(6);
    BST.print_tree();
    assert(BST.find_max() == 6 and BST.find_min() == 4);
} 



//finds height of empty tree
void height_empty_test(){
    BinarySearchTree BST;
    assert(BST.tree_height() == -1);
}

//finds height of perfect binary tree, meaning tree is symmetrical around root
void height_perfect_tree_empty(){
    BinarySearchTree BST;
    BST.insert(2);
    BST.insert(1);
    BST.insert(3);
    assert(BST.tree_height() == 1);
}

//tests for height of tree that is asymmetrical around the root
void height_BST_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(6);
    BST.insert(7);
    assert(BST.tree_height() == 2);
}

//tests that contain works when the node exists
void contains_true_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(6);
    BST.insert(7);
    assert(BST.contains(7));
}

//tests that contain works when node doesn't exist
void contains_false_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(6);
    BST.insert(7);
    assert(BST.contains(100) == false);
}

//checks that properly counting number of nodes for nonempty tree
void node_count_nonempty_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(6);
    BST.insert(7);
    assert(BST.node_count() == 4);
}

//properly count nodes for empty tree
void node_count_empty_test(){
    BinarySearchTree BST;
    assert(BST.node_count() == 0);
}

//tests count_total with no duplicates
void count_total_nodup_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(6);
    BST.insert(7);
    assert(BST.count_total() == 22);
}

//tests that count_total works when some nodes have count != 1
//This also tests if insert works for duplicates
void count_total_dup_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(6);
    BST.insert(5);
    assert(BST.count_total() == 20);
}

//finds max of a BST
void max_nonempty_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(6);
    assert(BST.find_max() == 6);
}

//Checks that max returns INT_MIN
void max_empty_test(){
    BinarySearchTree BST;
    assert(BST.find_max() == -2147483648);
}

//Finds min of nonempty tree
void min_nonempty_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(6);
    BST.insert(5);
    assert(BST.find_min() == 4);
}

//checks find_min with empty tree
void min_empty_test(){
    BinarySearchTree BST;
    assert(BST.find_min() == 2147483647);
}

//tests removing the root when it's the only node, so it's a leaf
void remove_root_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.print_tree();
    assert(BST.remove(5));
    assert(BST.node_count() == 0);
    BST.print_tree();
}

//tests removing a leaf
void remove_leaf_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(6);
    BST.insert(4);
    BST.insert(3);
    BST.print_tree();
    assert(BST.remove(3));
    BST.print_tree();
}

//tests removing a node with count > 1
void remove_dup(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(5);
    BST.remove(5);
    assert(BST.count_total() == 5);
}

//tests removing a nonroot node with one child
//It says I fail the autograder on this, but I'm not exactly sure why or how
void remove_one_child_test(){
    BinarySearchTree BST;
    BST.insert(10);
    BST.insert(8);
    BST.insert(9);
    BST.insert(7);
    BST.insert(3);
    BST.insert(5);
    BST.print_tree();
    assert(BST.remove(7));
    BST.insert(8);
    BST.print_tree();
}

//tests removing one child when the node being removed is the root
void remove_one_child_root_test(){
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(4);
    BST.insert(3);
    BST.print_tree();
    assert(BST.remove(5));
    BST.print_tree();
}

//
void remove_one_child_2_test(){
    BinarySearchTree BST;
    BST.insert(13);
    BST.insert(12);
    BST.insert(11);
    BST.print_tree();
    assert(BST.remove(12));
    BST.print_tree();
}
//tests removal when node has two children and replacement node is a leaf
void remove_two_child_test(){
    BinarySearchTree BST;
    BST.insert(7);
    BST.insert(4);
    BST.insert(6);
    BST.insert(5);
    BST.insert(3);
    BST.print_tree();
    assert(BST.remove(4));
    BST.print_tree();
}

//tests removal in case when removing a node with two children, and the
//node it's being replaced with is it's child 
void remove_two_child_2_test(){
    BinarySearchTree BST;
    BST.insert(10);
    BST.insert(5);
    BST.insert(6);
    BST.insert(7);
    BST.insert(9);
    BST.insert(8);
    BST.insert(4);
    BST.print_tree();
    assert(BST.remove(5));
    BST.print_tree();
}

//removing root node with 2 children
void remove_two_root_test(){
    BinarySearchTree BST;
    BST.insert(10);
    BST.insert(9);
    BST.insert(11);
    BST.print_tree();
    assert(BST.remove(10));
    BST.print_tree();
}

//Additional test case for calculating the  
void remove_near_root_test(){
    BinarySearchTree BST;
    BST.insert(10);
    BST.insert(12);
    BST.insert(11);
    BST.insert(13);
    BST.print_tree();
    assert(BST.remove(12));
    BST.print_tree();
}

//tests removing node that's not in tree
void remove_DNE_test(){
    BinarySearchTree BST;
    BST.insert(10);
    assert(not BST.remove(100000));
}

//tests that can readd a node when it has been removed from the root
void add_post_removal(){
    BinarySearchTree BST;
    BST.insert(10);
    BST.insert(11);
    BST.insert(12);
    BST.remove(10);
    BST.insert(9);
    BST.print_tree();
    assert(BST.node_count() == 3);
}

//tests copy constructor with an empty BST
void copyconstructor_empty_test(){
    BinarySearchTree BST;
    BinarySearchTree BST_2(BST);
    assert(BST_2.node_count() == 0);
}

//Having issues with one removal case, decided to move to unit_test
void failed_test(){
    BinarySearchTree bst;
    int values[]  = {4, 2, 11, 15, 9, 1, -6, 5, 3, 15, 2, 5, 13, 14};
    int numValues = sizeof(values) / sizeof(int);

    for (int i = 0; i < numValues; i++) {
        bst.insert(values[i]);
    }
    bst.print_tree();
    bst.remove(11);
    assert(bst.node_count() == 10);
}

//tests copy constructor for nonempty BST
void copyconstructor_test(){
    BinarySearchTree BST;
    BST.insert(10);
    BST.insert(5);
    BST.insert(7);
    BinarySearchTree BST_2;
    BST_2 = BST;
    BST_2.print_tree();
    assert(BST_2.count_total() == 22 and BST_2.node_count() == 3);
}