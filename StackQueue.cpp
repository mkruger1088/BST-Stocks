#include "StockQueue.h"

//******************************************************
// Function: StockQueue
//
// Purpose: StockQueue class default constructor
// Sets Nodes to NULL
//
//******************************************************

StockQueue::StockQueue()
{
	front = NULL;
	rear = NULL;
}

//******************************************************
// Function: StockQueue
//
// Purpose: Parameterized StockQueue class constructor
//
//******************************************************

StockQueue::StockQueue(const StockQueue & rhs)
{
	StockQueue::NodeType *temp;
	temp = rhs.front;

	while (temp != NULL) {
		Enqueue(rhs.front->info);
		temp = temp->next;
	}

}

//******************************************************
// Function: ~StockQueue
//
// Purpose: StockQueue destructor
// Utilizes Clear() function
//
//******************************************************

StockQueue::~StockQueue()
{
	Clear();
}

//******************************************************
// Function: Clear
//
// Purpose: Empties the Queue
//
//******************************************************

void StockQueue::Clear()
{
	NodeType * temp;

	while (front != NULL) {
		temp = front;
		front = front->next;
		delete temp;
		cout << "The queue has been cleared!";
	}
	rear = NULL;
}

//******************************************************
// Function: Size
//
// Purpose: Returns the size of the queue
//
//******************************************************

int StockQueue::Size()
{
	return length;
}

//******************************************************
// Function: Enqueue
//
// Purpose: Adds to the queue
//
//******************************************************

void StockQueue::Enqueue(Stock s)
{
	NodeType* temp;
	temp = new NodeType;

	temp->info = s;
	temp->next = NULL;

	if (rear == NULL) {
		front = temp;
	}
	else {
		rear->next = temp;
	}

	cout << s.getName() << " was pushed to the queue!" << endl;
	rear = temp;
	length++;
}

//******************************************************
// Function: Dequeue
//
// Purpose: Removes the front item of the queue
//
//******************************************************

bool StockQueue::Dequeue(Stock & returnedStock)
{
	NodeType* temp;
	temp = front;

	if (temp != NULL) {
		returnedStock = front->info;
		cout << returnedStock.getName() << " was removed from the queue!" << endl;
		front = front->next;
		length--;
		return true; 
	}
	else
		return false;
}

//******************************************************
// Function: Operator=
//
// Purpose: Assignment operator overload for the
// StockQueue class.
//
//******************************************************

StockQueue & StockQueue::operator=(const StockQueue & rhs)
{
	StockQueue::NodeType *temp;
	temp = rhs.front;

	while (temp != NULL) {
		temp->info = rhs.front->info;
		temp = temp->next;
	}

	return *this;
}

//******************************************************
// Function: operator<<
//
// Purpose: Overloads the ostream operator for the
// StockQueue class
//
//******************************************************

ostream & operator<<(ostream & os, StockQueue & rhs)
{
	StockQueue::NodeType *temp;
	temp = rhs.front;
	if (temp == NULL) {
		cout << "Queue is empty..." << endl;
	}
	while (temp != NULL) {
		os << temp->info.getName() << endl;
		temp = temp->next;
	}
	return os;
}
