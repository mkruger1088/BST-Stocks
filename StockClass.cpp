//***************************************************************
// File: StockClass.cpp
//
// Purpose: Implimentation file for Stock Class
//
// BCS 370 - Data Structures Homework #4
//
// Written By: Michael Kruger
//
// Updated: 12/7/2017
// -Added Operator< and Operator> overloads for Stock Class
//
// Compiler: Visual C++ 2015
//***************************************************************
#include "StockClass.h"
	Stock::Stock() {
	name = new string;
	price = new double;
	shares = new double;
}

//******************************************************
// Function: Stock
//
// Purpose: Stock Parameterized Constructor
//
// Update Information
// ------------------
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Updated to work with pointer variables
// Big O: O(1)
//******************************************************

Stock::Stock(string n, double p, double s) {

	name = new string(n);
	price = new double(p);
	shares = new double(s);
}

//******************************************************
// Function: Stock
//
// Purpose: Copy Constructor for Stock class
//
// Update Information
// ------------------
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Updated to work with pointer variables
// Big O: O(1)
//******************************************************

Stock::Stock(const Stock & obj)
{
	name = obj.name;
	price = obj.price;
	shares = obj.shares;
}

//******************************************************
// Function: ~Stock
//
// Purpose: Destructor for stock class
//
// Big O: O(1)
//******************************************************

Stock::~Stock()
{
	name = NULL;
	price = NULL;
	shares = NULL;

}

//******************************************************
// Function: getName
//
// Purpose: Returns the name class member
//
// Big O: O(1)
//******************************************************

string Stock::getName() {
	return *name;
}

//******************************************************
// Function: setName
//
// Purpose: Sets the name class member
//
// Big O: O(1)
//******************************************************

void Stock::setName(string n) {
	*name = n;
}

//******************************************************
// Function: getPrice
//
// Purpose: Returns the price class member
//
// Big O: O(1)
//******************************************************

double Stock::getPrice() {
	return *price;
}

//******************************************************
// Function: setPrice
//
// Purpose: Sets the price class member
//
// Big O: O(1)
//******************************************************

void Stock::setPrice(double p) {
	*price = p;
}

//******************************************************
// Function: getShares
//
// Purpose: Returns the shares class member
//
// Big O: O(1)
//******************************************************

double Stock::getShares() {
	return *shares;
}

//******************************************************
// Function: setShares
//
// Purpose: Sets the shares class member
//
// Big O: O(1)
//******************************************************

void Stock::setShares(double s) {
	*shares = s;
}

//******************************************************
// Function: CalculateValue
//
// Purpose: Returns the total price of the shares
//
// Big O: O(1)
//******************************************************

double Stock::CalculateValue() {
	double total = 0;
	total = (*price) * (*shares);

	return total;
}

//******************************************************
// Function: operator=
//
// Purpose: Overloads the assignment operator
// to work with the stock class
//
// Big O: O(1)
//******************************************************

void Stock::operator=(const Stock & obj)
{
	name = obj.name;
	price = obj.price;
	shares = obj.shares;
}

//******************************************************
// Function: operator==(Stock&, Stock&)
//
// Purpose: Overloads the ostream operator to work
// with the Stock class
//
// Update Information
// ------------------
// Name: Michael Kruger
// Date: 12/7/2017
// Description: Fixed the function so it does not cause
// a stack overflow
//
// Big O: O(1)
//******************************************************

bool operator==(Stock & lhs, Stock & rhs)
{
	if (*lhs.name == *rhs.name) {
		return true;
	}
	else return false;
}

//******************************************************
// Function: Operator<
//
// Purpose: Compares two stock name values to see if
//one is less than the other
// Big O: O(1)
//******************************************************

bool operator<(Stock & lhs, Stock & rhs)
{
	if (*lhs.name < *rhs.name) {
		return true;
	}
	else return false;
}

//******************************************************
// Function: Operator>
//
// Purpose: Compares two stock name values to see if
//one is greater than the other
// Big O: O(1)
//******************************************************

bool operator>(Stock & lhs, Stock & rhs)
{
	if (*lhs.name > *rhs.name) {
		return true;
	}
	else return false;
}

//******************************************************
// Function: operator<<
//
// Purpose: Overloads the ostream operator to work
// with the Stock class
// Big O: O(1)
//******************************************************

ostream & operator<<(ostream & os, const Stock & obj) //Overloads outstream operator for outputting Stock class members
{
	os << obj.name;
	os << "\t";
	os << obj.price;
	os << "\t";
	os << obj.shares;
	os << endl;

	return os;
}

//******************************************************
// Function: operator>>
//
// Purpose: Instream operator overload to allow for
// user input on a class object.
// Big O: O(1)
//******************************************************

/*
istream & operator >> (istream & is, Stock & obj)
{
	is >> obj.name;
	is >> obj.price;
	is >> obj.shares;

	return is;
}*/
