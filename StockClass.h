//***************************************************************
// File: Stock.h
//
// Purpose: Header file for Stock Portfolio project Stock Class
//
// BCS 370 - Data Structures Homework #4
//
// Written By: Michael Kruger
//
// Compiler: Visual C++ 2015
//
// Updated 12/7/2017:
// -Added operator= overload for Stock object comparisons
//***************************************************************
#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>

using namespace std;

class Stock { //Stock Class - Protoype
private:
	string *name; //Name of stock
	double *price; //Price of stocks
	double *shares; //Number of shares for a given stock
public:
	Stock(); //Default Constructor
	Stock(string n, double p, double s); //Parameterized Constructor
	Stock(const Stock &obj); //Copy Constructor
	~Stock(); //Stock Class Destructor

	string getName(); //Getter function to return the name of a stock
	void setName(string n); //Setter function to set the name of a stock

	double getPrice(); //Getter function to return the price of a stock
	void setPrice(double p);

	double getShares(); //Getter function to return the amount of shares for a stock
	void setShares(double s);

	//Calculates the value of a given stock by multiplying the price
	//of a given stock by the number of shares it holds.
	double CalculateValue();

	void operator= (const Stock &obj); //Overloads the assignment operator
	friend bool operator==(Stock &lhs, Stock& rhs); //Overloads assignment operator for Stock object comparison
	friend bool operator<(Stock &lhs, Stock& rhs); //Overloads < operator
	friend bool operator>(Stock &lhs, Stock& rhs); //Overloads the > operator

	friend ostream& operator<<(ostream& os, const Stock &obj);//Overloads the outstream operator for printing class-member values
};

#endif