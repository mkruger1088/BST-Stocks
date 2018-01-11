#ifndef STOCKQUEUE_H
#define STOCKQUEUE_H

#include "StockClass.h"

class StockQueue {
private:
	struct NodeType {
		Stock info;
		NodeType* next;
	};

	NodeType* front;
	NodeType* rear;
	int length = 0;

public:
	StockQueue();
	StockQueue(const StockQueue& rhs);
	~StockQueue();

	void Clear();
	int Size();
	void Enqueue(Stock s);
	bool Dequeue(Stock& returnedStock);
	StockQueue & operator=(const StockQueue& rhs);
	friend ostream& operator<<(ostream& os, StockQueue& s);

};

#endif