/*
 * SelectionSort.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */


#include "SelectionSort.h"
#include "VectorSorter.h"
#include <string>


/**
 * Constructor.
 * @param name the name of this algorithm.
 */
SelectionSort::SelectionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
SelectionSort::~SelectionSort() {}

/**
 * Run the selection sort algorithm.
 * @throws an exception if an error occurred.
 */
void SelectionSort::run_sort_algorithm() throw (string)
{
    int sizem1 = Sorter::size - 1;

    // For each element of the vector ...
    for (int i = 0; i < sizem1; i++)
    {
        Element smallest = VectorSorter::data[i];
        int index_of_smallest = i;

        // ... find the index of the smallest value
        // in the rest of the vector.
        for (int j = i + 1; j < Sorter::size; j++)
        {
            VectorSorter::Sorter::compare_count++;

            if (VectorSorter::data[j] < smallest)
            {
                smallest = VectorSorter::data[j];
                index_of_smallest = j;
            }
        }

        // Swap in the smallest value if it isn't already there.
        if (i != index_of_smallest) swap(i, index_of_smallest);
    }
}

