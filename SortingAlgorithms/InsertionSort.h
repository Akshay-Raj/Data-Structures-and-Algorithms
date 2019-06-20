/*
 * InsertionSort.h
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

#include "VectorSorter.h"

/**
 * The class that implements the insertion sort algorithm
 * for a vector of data.
 */
class InsertionSort: public VectorSorter
{
public:
    InsertionSort(string name);
    virtual ~InsertionSort();

    virtual void run_sort_algorithm() throw (string);
};



#endif /* INSERTIONSORT_H_ */
