#ifndef STOCKSTACK_H
#define STOCKSTACK_H
#include "StockClass.h"
const int max_size = 10;
class StockStack {
private:
	int top;
	int max = 10;
	Stock items[max_size];
public:
	StockStack();
	StockStack(int max);
	StockStack(const StockStack& rhs);
	~StockStack();

	void Clear();
	int Size();
	int MaxStorage();
	bool Push(Stock s);
	bool Pop();
	bool Top(Stock &returnedStock);
	StockStack & operator=(StockStack& rhs);
	friend ostream& operator<<(ostream& os, StockStack& s);
};



#endif