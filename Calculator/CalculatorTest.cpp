/*
 * CalculatorTest.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: akshayraj
 */

//AKSHAY RAJ BASAVANAGUDI RAJENDRA
#include <iostream>
#include <cstdlib>
#include <string>
#include "Calculator.h"
#include <exception>

using namespace std;

void calculate();

int main()
{
	calculate();
}

void calculate()
{
	CalculatorStream res;
    while(true)
	{
		cout << res.expression() << endl;
	}
}
