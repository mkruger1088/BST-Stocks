//***************************************************************
// File: StockBST.h
//
// Purpose: Header file for Stock Binary Search Tree
//
// BCS 370 - Data Structures Homework #5
//
// Written By: Michael Kruger
//
// Compiler: Visual C++ 2015\
//***************************************************************

#ifndef STOCKBST_H
#define STOCKBST_H

#include <iostream>
#include "StockClass.h"
using namespace std;

class StockBST {
private:
	struct StockBSTNode {
		StockBSTNode* left;
		StockBSTNode* right;
		Stock info;
	};
	
	StockBSTNode *root;		
	int length; //Tracks size of the tree

	//Helper Functions
	void Add(StockBSTNode*& root, Stock s);
	void Inorder(StockBSTNode* root);
	void Preorder(StockBSTNode* root);
	void Postorder(StockBSTNode* root);
	void Clear(StockBSTNode* root);
	void StockBST::CopyTree(StockBSTNode*& copy, const StockBSTNode* originalTree); //Copies one tree to another
	bool RetrieveItem(StockBSTNode * m_root, string s, double &shares);
	
public:
	StockBST(); //Default Constructor
	StockBST(const StockBST& rhs); //Copy Constructor
	~StockBST(); //Destructor

	void Clear(); //Clears the tree
	int Size(); //Returns the size of the tree
	void Add(Stock s); //Sorted by NAME!
	void Preorder(); //Process Node, Left, Right (Runtime: n)
	void Inorder(); //Left, Process Node, Right (Runtime: n)
	void Postorder(); //Left, Right, Process Node (Runtime: n)
	bool getShares(string name, double& shares); //Use a Preoder() to search through the tree
	StockBST& operator=(const StockBST& rhs); //Assignment overload for StockBST class
	void PrintTree(StockBSTNode *root, ostream& os);
	
	friend ostream& operator<<(ostream& os, StockBST s); //Ostream operator overload for StockBST Class (Friend)
};




#endif