//============================================================================
// Name        : Calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//AKSHAY RAJ BASAVANAGUDI RAJENDRA
#include <iostream>
#include <cstdlib>
#include <string>
#include "Calculator.h"
#include <exception>


using namespace std;

const char number = '8';

CalculatorStream cstream;

CalculatorStream::CalculatorStream() : flag(0), temp(0) {}

void CalculatorStream::unget(Calculator c)
{
	temp = c;
	flag = true;
}

Calculator CalculatorStream::get()
{
	if(flag)
	{
		flag = false;
		return temp;
	}
	char character;
	cin >> character;
	switch(character)
	{
	case '+' :
	case '-' :
	case '*' :
	case '/' :
	case '(' :
	case ')' :
	case '=' :
		return Calculator(character);
	case '0' :
	case '1' :
	case '2' :
	case '3' :
	case '4' :
	case '5' :
	case '6' :
	case '7' :
	case '8' :
	case '9' :
	{
		cin.unget();
		double val;
		cin >> val;
        return Calculator(number,val);
	}
	default:
		return Calculator(' ');
	}
}


double CalculatorStream::expression()
{
	double val = term();
	while(true)
	{
		Calculator c = cstream.get();
		switch(c.character)
		{
		case '+': val += term(); break;
		case '-': val -= term(); break;
		default:
			cstream.unget(c);
			return val;
		}
	}
}

double CalculatorStream::term()
{
	double val = factor();
	while(true)
	{
		Calculator c = cstream.get();
		switch(c.character)
		{
		case '*': val *= factor(); break;
		case '/': {
			double d = factor();
			if(d == 0)
			{
				cout << "***** Division by zero" << endl;
			}
			else
			{
				val /= d;
			}
			break;
		}
		default:
			cstream.unget(c);
			return val;
		}
	}
}

double CalculatorStream::factor()
{
	Calculator c = cstream.get();
	switch(c.character)
	{
	case '(': {
		double d = expression();
		c = cstream.get();
		if(c.character != ')')
		{
			cout << "***** Missing ')'" << endl;
		}
		return d;
	}
	case ')': {
		double d = expression();
	    c = cstream.get();
	    if(c.character != '(')
		{
	    	cout << "***** Missing '('" << endl;
		}
	    return d;
	}
	case '-' :
		return - factor();
	case '+' :
		return + factor();
	default :
		return c.value;
	}
}


