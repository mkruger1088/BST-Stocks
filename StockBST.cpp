//***************************************************************
// File: StockBST.cpp
//
// Purpose: StockBST implementation
//
// BCS 370 - Data Structures Homework #5
//
// Written By: Michael Kruger
//
// Compiler: Visual C++ 2015
//***************************************************************
#include "StockBST.h"

//******************************************************
// Function: Default Constructor
//
// Purpose: Initializes a StockBST object
// Big O: O(1)
//******************************************************

StockBST::StockBST()
{
	root = NULL;
	length = 0;
}

//******************************************************
// Function: Copy Constructor
//
// Purpose: Initializes a StockBST object copy
// Big O: O(1)
//******************************************************

StockBST::StockBST(const StockBST & rhs)
{
	CopyTree(root, rhs.root);
}

//******************************************************
// Function: Destructor
//
// Purpose: Utilizes Clear function to clear the BST
// Big O: O(n)
//******************************************************

StockBST::~StockBST()
{
	Clear(root);
}

//******************************************************
// Function: Clear
//
// Purpose: Empties the BST
// Big O: O(1)
//******************************************************

void StockBST::Clear()
{
	Clear(root);
	root = NULL;
}

//******************************************************
// Function: Size
//
// Purpose: Returns the size of the tree
// Big O: O(1)
//******************************************************

int StockBST::Size()
{
	return length;
}

//******************************************************
// Function: Add - Parameterized
//
// Purpose: Helper function for Add
// Big O: O(n)
//******************************************************

void StockBST::Add(StockBSTNode*& m_root, Stock s)
	{
		if (m_root == NULL) {
			m_root = new StockBSTNode;
			m_root->right = NULL;
			m_root->left = NULL;
			m_root->info = s;
		}
		else if (s < root->info) {
			Add(m_root->left, s);
		}
		else
			Add(m_root->right, s);
	}

//******************************************************
// Function: Inorder
//
// Purpose: Inorder Traversal
// Big O: O(n)
//******************************************************

void StockBST::Inorder(StockBSTNode * root)
{
	if (root != NULL) {
		Inorder(root->left);
		cout << root->info.getName() << endl;
		Inorder(root->right);
	}
}

//******************************************************
// Function: Preorder
//
// Purpose: Preorder Traversal
// Big O: O(n)
//******************************************************

void StockBST::Preorder(StockBSTNode * root)
{
	if (root != NULL) {
		cout << root->info.getName() << endl;
		Preorder(root->left);
		Preorder(root->right);
	}
}

//******************************************************
// Function: Postorder
//
// Purpose: Postorder Traversal

// Big O: O(n)
//******************************************************

void StockBST::Postorder(StockBSTNode * root)
{
	if (root != NULL) {
		Postorder(root->left);
		Postorder(root->right);
		cout << root->info.getName() << endl;
	}
}

//******************************************************
// Function: Clear - Parameterized
//
// Purpose: Helper function for Clear
// Big O: O(n)
//******************************************************

void StockBST::Clear(StockBSTNode * root)
{
	if (root != NULL) {
		Clear(root->left);
		Clear(root->right);
		delete root;
	}
	length = 0;
}

//******************************************************
// Function: Add
//
// Purpose: Calls the Add helper function
// Big O: O(n)
//******************************************************

void StockBST::Add(Stock s)
{
	Add(root, s);
	length++;
}

//******************************************************
// Function: Preorder
//
// Purpose: Calls the Preorder helper function
// Big O: O(n)
//******************************************************

void StockBST::Preorder()
{
	Preorder(root);
}

//******************************************************
// Function: Inorder
//
// Purpose: Calls the Inorder helper function
// Big O: O(n)
//******************************************************

void StockBST::Inorder()
{
	Inorder(root);
}

//******************************************************
// Function: Postorder
//
// Purpose: Calls the Postorder helper function
// Big O: O(n)
//******************************************************

void StockBST::Postorder()
{
	Postorder(root);
}

//******************************************************
// Function: getShares
//
// Purpose: Returns the number of shares by reference
// assuming a stock of a given name is found
// Big O: (n)
//******************************************************

bool StockBST::getShares(string name, double & shares)
{
	if (RetrieveItem(root, name, shares) == 1)
		return true;
	else
		return false;

}

//******************************************************
// Function: Copytree - Helper Function
//
// Purpose: Copies one tree to another tree
// Big O: O(n)
//******************************************************

void StockBST::CopyTree(StockBSTNode*& copy, const StockBSTNode* originalTree)
{
	if (originalTree == NULL)
		copy = NULL;
	else
	{
		copy = new StockBSTNode;
		copy->info = originalTree->info;
		CopyTree(copy->left, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}
}

//******************************************************
// Function: RetrieveItem - Helper Function
//
// Purpose: Retrieves a stock items information
// from the binary search tree
// Big O: O(n)
//******************************************************

bool StockBST::RetrieveItem(StockBSTNode * m_root, string s, double &shares)
{
	{
		if (m_root == NULL)
			return false;
		else if (s < m_root->info.getName())
			RetrieveItem(m_root->left, s, shares);
		else if (s > m_root->info.getName())
			RetrieveItem(m_root->right, s, shares);
		else
		{
			shares = m_root->info.getShares();
			return true;
		}
	}

}

//******************************************************
// Function: Operator=
//
// Purpose: Overloads the assignment operator for
// StockBST class objects
// Big O: O(n)
//******************************************************

StockBST & StockBST::operator=(const StockBST & rhs)
{
	if (this->root != NULL) {
		Clear();
	}
	
	CopyTree(this->root, rhs.root);

	return *this;
}

//******************************************************
// Function: PrintTree
//
// Purpose: Prints the binary search tree
// Big O: O(n)
//******************************************************

void StockBST::PrintTree(StockBSTNode * root, ostream & os)
{
	if (root != NULL)
	{
		PrintTree(root->left, os);
		os << "Name: " << root->info.getName() << endl;
		os << "Price: " << root->info.getPrice() << endl;
		os << "Shares: " << root->info.getShares() << endl;
		PrintTree(root->right, os);
	}

}

//******************************************************
// Function: Operator<<
//
// Purpose: Overloads the ostream operator
// Big O: O(n)
//******************************************************

ostream & operator<<(ostream & os, StockBST s)
{
		if (s.root != NULL) {
			s.PrintTree(s.root, os);
		}
	return os;
}
