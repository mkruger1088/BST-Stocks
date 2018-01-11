//***************************************************************
// File: Portfolio.cpp
//
// Purpose: Implimentation file for the Portfolio Class
//
// Written By: Michael Kruger
//
// Compiler: Visual C++ 2015
//***************************************************************

#include "PortfolioClass.h"
//****************************************************
// Function: Portfolio
//
// Purpose: Default Constructor for Portfolio class
//
// Update Information
// ------------------
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Utilizes Initialize function to set up
// an object of Portfolio class with pointers. 
//****************************************************

Portfolio::Portfolio()
{
	Initialize();
}

//****************************************************
// Function: Portfolio
//
// Purpose: Parameterized Constructor for Portfolio class
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Utilizes Initialize function to set up
// an object of Portfolio class with pointers with a
// given variable, 'size'.
//****************************************************

Portfolio::Portfolio(int s)
{
	size = s;
	Initialize();
}
//****************************************************
// Function: Portfolio
//
// Purpose: Copy Constructor for Portfolio class
//
// Update Information
// ------------------
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Copies given Portfolio class object to
// current Portfolio class object
//****************************************************

Portfolio::Portfolio(const Portfolio & obj)
{
	size = obj.size;
	for (int i = 0; i < size; i++) {
		stocks[i] = obj.stocks[i];
	}
}

//********************************************************
// Function: ~Portfolio
//
// Purpose: Destructor for Portfolio class
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Deallocates heap memory for 'stocks'array
//********************************************************

Portfolio::~Portfolio()
{
	delete[] stocks;
}

//****************************************************
// Function: Clone
//
// Purpose: Copies a class object
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Utilizes Initialize function to set up
// an object of Portfolio class with pointers. 
//****************************************************

Portfolio * Portfolio::Clone()
{
	return new Portfolio(*this);
}

//****************************************************
// Function: Set
//
// Purpose: Sets value to a given stock index
//
// Update Information
// ------------------
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Updated to work with pointer variables
//****************************************************

void Portfolio::Set(int index, Stock* s)
{
	if (index >= sizeof(stocks) || index < 0) {
		cout << "The index you requested does not exist!" << endl;
	}
	else {

	}
}

//****************************************************
// Function: Get
//
// Purpose: Gets value from a given stock index
//****************************************************
Stock Portfolio::Get(int index) {
	return stocks[index];
}

//****************************************************
// Function: PriceRangeCount
//
// Purpose: Returns the number of stocks within a
// certain price range.
//****************************************************

int Portfolio::PriceRangeCount(double lowerBound, double upperBound)
{
	int total = 0;
	for (int i = 0; i < size; i++) {
		if (stocks[i].getPrice() >= lowerBound && stocks[i].getPrice() <= upperBound) {
			total++;
		}
	}
	return total;
}

//****************************************************
// Function: MostShares
//
// Purpose: Returns the stock with the most shares
//
// Update Information
// ------------------
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Fixed to correctly give highest share
// value from array.
//****************************************************

Stock Portfolio::MostShares()
{
	int temp = 0;
	double highest = 0;
	for (int i = 0; i < size; i++) {
		if (stocks[i].getShares() > highest)  //Checks for the highest shares index
			temp = i; //Stores highest index
	}

	return stocks[temp];
}

//****************************************************
// Function: FindByName
//
// Purpose: Searches the array for a specifically
// named stock
//
// Update Information
// ------------------
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Updated to properly return the name
// of the desired stock
//****************************************************

bool Portfolio::FindByName(string name, Stock &v)
{
	for (int i = 0; i < size; i++) {
		if (name == v.getName()) {
			v = stocks[i];
			return true;
		}
		else
		{
			cout << "Name not found!" << endl;
		}
	}
	return false;
}

//******************************************************
// Function: TotalValue
//
// Purpose: Returns the total share value of all stocks
//******************************************************

double Portfolio::TotalValue()
{
	double total = 0.00;

	for (int i = 0; i < size; i++)
	{
		total += stocks[i].CalculateValue();
	}
	return total;
}

//****************************************************
// Function: Size
//
// Purpose: Returns the size of the 'stocks' array
//****************************************************

int Portfolio::Size() {
	return sizeof(stocks);
}

//******************************************************
// Function: Initialize
//
// Purpose: Initializes the class member variables
//
// Update Information
// ------------------
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Updated to work with pointer variables
//******************************************************

void Portfolio::Initialize()
{
	string name = "N/A";
	double price = 0.00;
	double shares = 0.00;
	size = 0;

	for (int i = 0; i < size; ++i) {
		stocks = new Stock[size];
	}

	for (int i = 0; i < size; i++) { //Sets values to array elements
		stocks[i].setName(name);
		stocks[i].setPrice(price);
		stocks[i].setShares(shares);
	}
}

//******************************************************
// Function: Resize
//
// Purpose: Copies the array to a placeholder,
// deletes the allocated memory to the original to avoid
// memory leaks, and finally copies it back to the newly
// sized array and deletes the placeholder to deallocate
// heap used to store it
//******************************************************

void Portfolio::Resize(int newSize)
{
	Stock *newStock = new Stock[newSize];

	for (int i = 0; i < newSize; i++) {
		stocks[i] = newStock[i];
	}
	delete[] stocks;

	for (int i = 0; i < newSize; i++) {
		Stock *stocks = new Stock[newSize];
		stocks[i] = newStock[i];
	}

	delete[] newStock;

}

//******************************************************
// Function: GetAuthor
//
// Purpose: Returns the author's name
//******************************************************

string Portfolio::GetAuthor()
{
	string author = "Michael Kruger";

	return author;
}

//******************************************************
// Function: Operator=
//
// Purpose: Overloads the assignment operator to work
// with the Portfolio class.
//
// Update Information
// ------------------
//
// Name: Michael Kruger
// Date: 10/11/2017
// Description: Updated to work with pointer variables
//
//******************************************************

void Portfolio::operator=(const Portfolio & obj)
{
	delete[] stocks;
	size = obj.size;

	for (int i = 0; i < size; i++) {
		Stock *stocks = new Stock[size];
		stocks[i] = obj.stocks[i];
	}

}

//******************************************************
// Function: Operator<<
//
// Purpose: Overloads the ostream operator to allow for
// class objects to be printed.
//******************************************************

ostream & operator<<(ostream & os, const Portfolio & obj)
{
	os << "Stocks:" << endl;
	for (int i = 0; i < obj.size; i++) {
		os << i << ": ";
		os << obj.stocks[i] << endl;
	}

	return os;
}
