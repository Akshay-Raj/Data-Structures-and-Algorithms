/*
 * Node.h
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */

#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    Node* next;
    Node();
    Node(const Element& other);
    Element element;
};



#endif /* NODE_H_ */
