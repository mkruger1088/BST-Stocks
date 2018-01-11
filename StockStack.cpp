#include "StockStack.h"

//******************************************************
// Function: StockStack
//
// Purpose: StockStack class default constructor
// Initializes stack
//******************************************************

StockStack::StockStack()
{
	top = -1;
	items[10];
}

//******************************************************
// Function: StockStack
//
// Purpose: Parameterized StockStack constructor
//******************************************************

StockStack::StockStack(int max)
{
	top = -1;
	items[max];

}

//******************************************************
// Function: StockStack
//
// Purpose: Copy Constructor for StockStack class
//******************************************************

StockStack::StockStack(const StockStack & rhs)
{
	top = rhs.top;
	for (int i = 0; i < rhs.max; i++) {
		items[i] = rhs.items[i];
	}
}

//******************************************************
// Function: ~StockStack
//
// Purpose: StockStack class destructor
// Clear the stack
//******************************************************

StockStack::~StockStack()
{
	Clear();
}

//******************************************************
// Function: Clear
//
// Purpose: Clears the stack
//******************************************************

void StockStack::Clear()
{
	top = -1;
	cout << "The stack is cleared!" << endl;
}

//******************************************************
// Function: Size
//
// Purpose: returns the size of the stack
//******************************************************

int StockStack::Size()
{
	return top+1;
}

//******************************************************
// Function: MaxStorage
//
// Purpose: Returns the maximum size for the stack
//
//******************************************************

int StockStack::MaxStorage()
{
	return max;
}

//******************************************************
// Function: Push
//
// Purpose: Increases the stack size and adds a new
// stock to the top of the stack
//
//******************************************************

bool StockStack::Push(Stock s)
{
	if (top != max) {
		top++;
		cout << s.getName() << " pushed to the top of the stack!" << endl;
		items[top] = s;
		return true;
	}
	else return false;
}

//******************************************************
// Function: Pop
//
// Purpose: Removes the top item from the stack
//
//******************************************************

bool StockStack::Pop()
{
	if (top != 0) {
		cout << items[top].getName() << " removed from the stack!" << endl;
		top--;
		return true;
	}
	else return false;
}

//******************************************************
// Function: Top
//
// Purpose: Returns the top item of the stack
//
//******************************************************

bool StockStack::Top(Stock & returnedStock)
{
	if (top == -1) {
		cout << "The stack is empty, returning false!" << endl;
		return false;
	}
	else
	{
		returnedStock = items[top];
		cout << "Top returning true..." << endl;
		return true;
	}
}

//******************************************************
// Function: Operator=
//
// Purpose: Assignment operator overload for StackStock
// class objects
//
//******************************************************

StockStack & StockStack::operator=(StockStack & rhs)
{
	int temp = 0;
	while (temp != top) {
		items[temp] = rhs.items[temp];
		temp++;
	}
	return *this;
}

//******************************************************
// Function: Operator<<
//
// Purpose: Overloads the ostream operator for the 
// StockStack class
//
//******************************************************

ostream & operator<<(ostream & os, StockStack & s)
{
	if (s.top < 0) {
		cout << "The stack is empty..." << endl;
	}
	for(int i = 0; i < s.top+1; i++)
	{
		os << s.items[i].getName() << ", ";
	}

	return os;
}
