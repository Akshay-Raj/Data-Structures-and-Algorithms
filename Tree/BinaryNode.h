/*
 * BinaryNode.h
 *
 *  Created on: Apr 29, 2017
 *      Author: akshayraj
 */

/**
 * A node of a binary tree.
 */

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
public:
    BinaryNode(const int data);
    BinaryNode(const int data, BinaryNode *left, BinaryNode *right);
    virtual ~BinaryNode();

    int data;
    int height;  // node height

    BinaryNode *left;
    BinaryNode *right;

    BinaryNode* &get_left();
    BinaryNode* &get_right();
    int get_data();
    static void reset();

    static long probe_count;
    static long compare_count;

};


#endif // BINARY_TREE_PRINTER_H
