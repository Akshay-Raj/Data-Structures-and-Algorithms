/*
 * InsertionSort.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */

#include "InsertionSort.h"
#include <string>
#include "VectorSorter.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */

//REFERENCE - http://www.thecrazyprogrammer.com/2014/12/insertion-sort.html
void InsertionSort::run_sort_algorithm() throw (string)
{
    for(int i = 1 ; i < size; ++i)
    {
    	Element smallest = data[i];
    	int j = i - 1;
    	while((j >= 0) && (data[j-1] > smallest))
    	{
    		compare_count++;
    		data[j + 1] = data[j];
    		move_count++;
    		--j;
    	}
    	data[j] = smallest;
    	move_count++;
    }
    return;
}



