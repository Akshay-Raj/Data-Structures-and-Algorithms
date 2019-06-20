/*
 * Element.h
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;

    /***** Complete this class. *****/
    static void reset();
    static long get_copy_count();
    static long get_destructor_count();

    bool operator  >(const Element& other) const;
    bool operator  <(const Element& other) const;
    bool operator  >=(const Element& other) const;
    bool operator  <=(const Element& other) const;
    friend ostream& operator <<(ostream& outs,const Element& other);

private:
    long value;
    static long copy_count;
    static long destructor_count;
};

#endif /* ELEMENT_H_ */
