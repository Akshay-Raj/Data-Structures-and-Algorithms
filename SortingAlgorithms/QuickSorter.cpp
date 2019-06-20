/*
 * QuickSorter.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */

#include <iostream>
#include "QuickSorter.h"
#include <string>
#include "VectorSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, VectorSorter::data.size()-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */

//REFERENCE - https://codereview.stackexchange.com/questions/77782/quick-sort-implementation

void QuickSorter::quicksort(const int left, const int right)
{
	if (left >= right)
	{
		return;
	}
	Element pivot = choose_pivot(left,right);
	int part = partition(left, right, pivot);
	quicksort(left, part - 1);
	quicksort(part + 1, right);
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */

//REFERENCE - https://codereview.stackexchange.com/questions/77782/quick-sort-implementation
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
	const int middle = left + (right - left) / 2;
	std::swap(VectorSorter::data[middle],VectorSorter::data[left]);
	int i = left + 1;
	int j = right;
	while (i <= j)
	{
		while(i <= j && VectorSorter::data[i] <= pivot)
		{
			i++;
	    }
		while(i <= j && VectorSorter::data[j] > pivot)
		{
			j--;
	    }
		if (i < j)
		{
			std::swap(VectorSorter::data[i], VectorSorter::data[j]);
	    }
	}
	std::swap(VectorSorter::data[i - 1],VectorSorter::data[left]);
	return i - 1;
}



