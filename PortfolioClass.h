//***************************************************************
// File: Portfolio.h
//
// Purpose: Header file for Stock Portfolio Portfolio Class
//
// Written By: Michael Kruger
//
// Compiler: Visual C++ 2015
//***************************************************************

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "StockClass.h"

class Portfolio : Stock { //Inherited class Portfolio of Stock class (Prototype)
private:
	Stock* stocks; //Collection of stocks in Stock class
	int size; //Size of the 'stocks' array
public:
	Portfolio(); //Default Constructor
	Portfolio(int s); //Parameterized Constructor
	Portfolio(const Portfolio &obj); //Copy Constructor
	~Portfolio(); //Destructor

	Portfolio *Clone(); //Allocates new dynamic instance of Portfolio, returns pointer to new instance

	void Set(int index, Stock* s); //Sets stock values based on a given index

	Stock Get(int index); //Returns a stock based on a given index

	int PriceRangeCount(double lowerBound, double upperBound); //Returns price ranges based on given ranges

	Stock MostShares(); //Returns the stock with the most shares

	bool FindByName(string name, Stock &v); //Checks to see if a specificly named stock exists

	double TotalValue(); //Returns the total value of all stocks

	int Size(); //Returns the size of the stocks array

	void Initialize(); //Initializes the stocks array

	void Resize(int newSize); //Changes the size of the dynamic array 'stocks'

	string GetAuthor(); //Returns the program author's name

	void operator= (const Portfolio &obj); //Overloads the assignment operator for Portfolio class

	friend ostream& operator<<(ostream& os, const Portfolio& obj); //ostream overload for Portfolio function, allows for output of Portfolio class
};

#endif