/*
 * Node.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */

#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/
Node::Node()
{
	next = nullptr;
	element = NULL;
}
Node::Node(const Element& other)
{
	element = other;
    next = nullptr;
}

