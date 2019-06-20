//============================================================================
// Name        : Tree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "AvlTree.h"

using namespace std;

/**
 * Default constructor.
 */
AvlTree::AvlTree()
    : BinarySearchTree()
{
}

/**
 * Destructor.
 */
AvlTree::~AvlTree()
{
}

/**
 * Private method to compute the height of a subtree.
 * Overrides the base class method.
 * @param ptr pointer to the root node of the subtree.
 * @return the height of the subtree.
 */
int AvlTree::height(const BinaryNode *ptr) const
{
    return ptr == nullptr ? -1 : ptr->height;
}

/**
 * Private method to insert a data item into a subtree
 * and set the new root of the subtree.
 * Overrides the base class method.
 * @param data the data to insert.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::insert(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    balance(ptr);
}

/**
 * Private method to remove a data item from a subtree
 * and set the new root node of the subtree.
 * Do nothing if the data item is not found.
 * Overrides the base class method.
 * @param data the data to remove.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    balance(ptr);
}

/**
 * Private method to balance the tree.
 * @param ptr pointer to the node to balance.
 * @return pointer to the balanced node.
 */
BinaryNode *AvlTree::balance(BinaryNode* &ptr)
{
    if (ptr == nullptr) return ptr;

    // Left side too high.
    if (height(ptr->get_left()) - height(ptr->get_right()) > 1)
    {
        if (height(ptr->get_left()->get_left()) >= height(ptr->get_left()->get_right()))
        {
            ptr = singleRightRotation(ptr);
        }
        else
        {
            ptr = doubleLeftRightRotation(ptr);
        }
    }

    // Right side too high.
    else if (height(ptr->get_right()) - height(ptr->get_left()) > 1)
    {
        if (height(ptr->get_right()->get_right()) >= height(ptr->get_right()->get_left()))
        {
            ptr = singleLeftRotation(ptr);
        }
        else
        {
            ptr = doubleRightLeftRotation(ptr);
        }
    }

    // Recompute the node's height.
    ptr->height = (max(height(ptr->get_left()),
                       height(ptr->get_right())) + 1);

    if (checkBalance(ptr) < 0) {}
    return ptr;
}


/**
 * Case 1 (outside left-left): Rebalance with a single right rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */

//REFERENCE - http://emunix.emich.edu/~haynes/Papers/AVL/rotations.pdf

BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
    BinaryNode* k = k2->get_left();
    k2->get_left() = k->get_right();
    k->get_right() = k2;
    k2->height = max(height(k2->get_left()),height(k2->get_right())) + 1;
    k->height = max(height(k->get_left()), height(k->get_right())) + 1;
    return k;
}

/**
 * Case 2 (inside left-right): Rebalance with a double left-right rotation.
 * @param k3 pointer to the node to rotate.
 * @return pointer to the new root node.
 */

//REFERENCE - http://emunix.emich.edu/~haynes/Papers/AVL/rotations.pdf

BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
	k3->get_left() = singleLeftRotation(k3->get_left());
	BinaryNode *k = singleRightRotation(k3);
	return k;
}

/**
 * Case 3 (inside right-left): Rebalance with a double left rotation.
 * @param k1 pointer to the node to rotate.
 * @return pointer to the new root node.
 */

//REFERENCE - http://emunix.emich.edu/~haynes/Papers/AVL/rotations.pdf

BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
	k1->get_right() = singleRightRotation(k1->get_right());
	BinaryNode *k = singleLeftRotation(k1);
	return k;
}

/**
 * Case 4 (outside right-right): Rebalance with a single left rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */

//REFERENCE - http://emunix.emich.edu/~haynes/Papers/AVL/rotations.pdf

BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k1)
{
    BinaryNode* k = k1->get_right();
    k1->get_right() = k->get_left();
    k->get_left() = k1;
    k1->height = max(height(k1->get_left()),height(k1->get_right())) + 1;
    k->height = max(height(k->get_left()), height(k->get_right())) + 1;
    return k;
}

/**
 * Private method for a paranoid check of whether a tree node is balanced.
 * @param ptr pointer to the node to check.
 * @return the height of the node if balanced, -1 if the node is null,
 *         or -2 if unbalanced.
 */
int AvlTree::checkBalance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = checkBalance(ptr->get_left());
    int rightHeight = checkBalance(ptr->get_right());

    if ((abs(height(ptr->get_left()) - height(ptr->get_right())) > 1)
        || (height(ptr->get_left())  != leftHeight)
        || (height(ptr->get_right()) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
