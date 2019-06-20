/*
 * ShellSortSuboptimal.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */


#include "ShellSortSuboptimal.h"
#include <string>
#include "VectorSorter.h"


/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */

//REFERENCE - http://www.sanfoundry.com/cplusplus-program-implement-shell-sort/

void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
	int i,j;
    for(int gap = Sorter::size/2; gap > 0;gap /= 2)
    {
    	for(i = gap;i < Sorter::size; i += 1)
    	{
    		Element elem = VectorSorter::data[i];
    		Sorter::compare_count++;
    		for(j = i;j >= gap && VectorSorter::data[j - gap] > elem; j -= gap)
    		{
    			VectorSorter::data[j] = VectorSorter::data[j - gap];
    		    Sorter::move_count++;
    		}
    		VectorSorter::data[j] = elem;
    	}
    }
}


