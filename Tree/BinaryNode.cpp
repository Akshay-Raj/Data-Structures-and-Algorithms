/*
 * BinaryNode.cpp
 *
 *  Created on: Apr 29, 2017
 *      Author: akshayraj
 */

#include "BinaryNode.h"
#include <string>

long BinaryNode::probe_count;
long BinaryNode::compare_count;

/**
 * Constructor.
 * @param data the data item.
 */
BinaryNode::BinaryNode(const int data)
    : data(data), height(0), left(nullptr), right(nullptr)
{
}

/**
 * Constructor.
 * @param data the data item.
 * @param left the left link.`	a
 * @param right the right link.
 */
BinaryNode::BinaryNode(const int data, BinaryNode *left, BinaryNode *right)
  : data(data), height(0), left(left), right(right)
{
}

/**
 * Destructor.
 */
BinaryNode::~BinaryNode()
{
}

BinaryNode* &BinaryNode::get_left()
{
	probe_count++;
	return left;
}

BinaryNode* &BinaryNode::get_right()
{
	probe_count++;
	return right;
}

int BinaryNode::get_data()
{
	compare_count++;
	return data;
}

void BinaryNode::reset()
{
	probe_count = compare_count = 0;
}


