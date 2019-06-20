/*
 * Calculator.h
 *
 *  Created on: Apr 10, 2017
 *      Author: akshayraj
 */

//AKSHAY RAJ BASAVANAGUDI RAJENDRA
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
using namespace std;

struct Calculator {
		char character;
		double value;
		Calculator(char character) : character(character), value(0) {}
		Calculator(char character, double value) : character(character), value(value) {}
	};


class CalculatorStream
{
public:

	bool flag;
	Calculator temp;

	CalculatorStream();
	Calculator get();
	void unget(Calculator c);

	double expression();
	double term();
	double factor();
};



#endif /* CALCULATOR_H_ */
