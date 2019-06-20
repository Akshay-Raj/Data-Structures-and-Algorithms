/*
 * ShellSortOptimal.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */


#include "ShellSortOptimal.h"
#include "VectorSorter.h"
#include "math.h"
#include <string>

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */


//REFERENCE - http://www.bebetterdeveloper.com/algorithms/sorting/sorting-shell-sort.html
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    int h = 0;
    while(h < Sorter::size / 3)
    {
    	h = 3 * h + 1;
    }
    while(h > 0)
    {
    	for(int i = h; i < Sorter::size; i++)
    	{
    		Element elem = VectorSorter::data[i];
    		int j;
    		for(j = i; j >= h; j -= h)
    		{
    			Sorter::compare_count++;
    			if(VectorSorter::data[j - h] > elem)
    			{
    				VectorSorter::data[j] = VectorSorter::data[j - h];
    				Sorter::move_count++;
    			}
    			else
    				break;
    		}
    		VectorSorter::data[j] = elem;
    	}
    	h = (h - 1) / 3;
    }
}

