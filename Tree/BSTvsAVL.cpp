/*
 * BSTApp.cpp
 *
 *  Created on: Apr 29, 2017
 *      Author: akshayraj
 */

/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 */

#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <cstdlib>

#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;
using namespace std::chrono;

int N = 10;
int step = 10000;
void tree_operations(BinarySearchTree& T,double counts[][6]);
void print_results(double bst_counts[][6],double avl_counts[][6]);
string commafy(long n);

int main()
{
	double avl_counts[10][6];
	double bst_counts[10][6];
	AvlTree AVL;
	BinarySearchTree BST;
	tree_operations(AVL, avl_counts);
	tree_operations(BST, bst_counts);
	print_results(bst_counts, avl_counts);
	return 0;
}


void tree_operations(BinarySearchTree& T,double counts[][6])
{
	int i = 1;
	while(i <= N)
	{
		T.clear();
		T.setRoot();
		int size = step * i;
		BinaryNode::reset();
		int j = 0;
		steady_clock::time_point start_time = steady_clock::now();
		for(;j < size;j++)
		{
			int elem = rand() % size;
			T.insert(elem);
		}
		steady_clock::time_point end_time = steady_clock::now();
		int elapsed_time = duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		counts[i-1][0] = BinaryNode::probe_count;
		counts[i-1][1] = BinaryNode::compare_count;
		counts[i-1][2] = elapsed_time;
		BinaryNode::reset();
		j = 0;
		start_time = steady_clock::now();
		for(;j < size;j++)
		{
			int elem = rand() % size;
			T.contains(elem);
		}
		end_time = steady_clock::now();
		elapsed_time = duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		counts[i-1][3] = BinaryNode::probe_count;
		counts[i-1][4] = BinaryNode::compare_count;
		counts[i-1][5] = elapsed_time;
		i++;
	}
}

void print_results(double bst_counts[][6],double avl_counts[][6])
{
	int i = 0;
	while(i < N)
	{
		std::cout.precision(0);
		cout << step * (i + 1);
		int j = 0;
		while(j < 6)
		{
			cout << std::fixed << "," << bst_counts[i][j] << "," << avl_counts[i][j] << "";
			j++;
		}
		cout << endl;
		i++;
	}
}

string commafy(long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;
    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }
    return str;
}
