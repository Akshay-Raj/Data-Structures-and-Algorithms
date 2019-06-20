/*
 * MergeSort.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: akshayraj
 */

#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */

//REFERENCE - D.S Malik


void MergeSort::mergesort(LinkedList& list)
{
    /***** Complete this member function. *****/
	LinkedList first,second;
	if(list.get_head()!=list.get_tail())
	{
		move_count += list.get_size();
		list.split(first,second);
		if(first.get_size()!=0)
		{
			mergesort(first);
		}
		if(second.get_size() != 0)
			mergesort(second);

		merge(list,first,second);
	}
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */

//REFERENCE - D.S.Malik
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
	while(sublist1.get_head()!=nullptr || sublist2.get_head()!=nullptr)
	{
		if(sublist1.get_head()==nullptr && sublist2.get_head()!=nullptr)
		{
			list.concatenate(sublist2);
		}
		else if(sublist1.get_head()!=nullptr && sublist2.get_head()==nullptr)
		{
			list.concatenate(sublist1);
		}
		else if(sublist1.get_head()->element.get_value()<=sublist2.get_head()->element.get_value())
		{
			compare_count++;
			move_count++;
			list.add(sublist1.remove_head());
		}
		else
		{
			compare_count++;
			move_count++;
			list.add(sublist2.remove_head());
		}
	}
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }



