//============================================================================
// Name        : SortingAlgorithms.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Element.h"

using namespace std;

/***** Complete this class. *****/


long Element::copy_count;
long Element::destructor_count;

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
	value = other.value;
    copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    destructor_count++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

void Element::reset()
{
    copy_count = destructor_count = 0;
}

bool Element::operator >(const Element& other) const
{
    return value > other.value;
}

bool Element::operator <(const Element& other) const
{
    return value < other.value;
}

bool Element::operator >=(const Element& other) const
{
    return value >= other.value;
}

bool Element::operator <=(const Element& other) const
{
    return value <= other.value;
}
ostream& operator <<(ostream& outs,const Element& other)
{
	outs << other.get_value();
	return outs;
}

long Element::get_copy_count() { return copy_count; }

long Element::get_destructor_count() { return destructor_count; }
