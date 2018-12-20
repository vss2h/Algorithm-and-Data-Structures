//CSCI 3110-001
//Project6

// This is the "WordTree.cpp" file

#include "WordTree.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Constructor that creates an empty tree
WordTree::WordTree()
{
	root = nullptr;
}

//a public function that inserts a  word in the tree by calling a private function
void WordTree::insert(string wrd)
{
	insert(wrd, root);
}

// a public function that  searches for the word in the tree by calling a private function
void WordTree::findNode(string wrd) const
{
	findNode(wrd, root);
}

// Recursive function that adds a word to the tree, and increment its count if the word is already in the tree
void WordTree::insert(string wrd, struct TreeNode*& subTreeRoot)
{
	if (subTreeRoot == nullptr)
	{
		subTreeRoot = new TreeNode;
		subTreeRoot->word = wrd;
		subTreeRoot->left_child = nullptr;
		subTreeRoot->right_child = nullptr;
		subTreeRoot->count = 1;
	}
	else if (wrd < subTreeRoot->word)
	{
		insert(wrd, subTreeRoot->left_child);
	}
	else if (wrd > subTreeRoot->word)
	{
		insert(wrd, subTreeRoot->right_child);
	}
	else if (subTreeRoot->word == wrd)
	{
		subTreeRoot->count++;
	}

}

// a private function that  searches for a word in the tree and outputs the word and its count if the word is present
// otherwise displays a message stating that the word was not found.
void WordTree::findNode(string wrd, TreeNode * subTreeRoot) const
{
	if (subTreeRoot == nullptr)
	{
		cout << "The word '" << wrd << "' was not found in the text.\n ";
	}

	else if (wrd < subTreeRoot->word)
	{
		findNode(wrd, subTreeRoot->left_child);
	}
	else if (wrd > subTreeRoot->word)
	{
		findNode(wrd, subTreeRoot->right_child);
	}
	else if (subTreeRoot->word == wrd)
	{
		cout << "The word '" << wrd << "' occurs " << subTreeRoot->count << " time(s) in the text.\n";
	}

}

// Recursive function that traverses the tree in order, outputting the words(and their counts) 
void WordTree::printInOrder(int num, TreeNode * subTreeRoot, int & total) const
{
	if (subTreeRoot != nullptr)
	{
		printInOrder(num, subTreeRoot->left_child, total);
		if (subTreeRoot->count >= num)
		{
			cout << subTreeRoot->word << " (" << subTreeRoot->count << ")\n";
			total++;
		}
		printInOrder(num, subTreeRoot->right_child, total);
	}
}

//a public function that accepts a single integer argument, calls a private function, and prints the total number 
//of nodes that exceed the threshold count
void WordTree::printInOrder(int num) const
{
	int total = 0;
	printInOrder(num, root, total);
	cout << total << " nodes had words with " << num << " or more occurrence(s).\n";
}

// destructor
WordTree::~WordTree()
{
	deleteNodes(root);
}

// a recursive function that explicitly releases all nodes allocated during program execution
void WordTree::deleteNodes(TreeNode* subTreeRoot)
{
	if (subTreeRoot)
	{
		deleteNodes(subTreeRoot->left_child);
		deleteNodes(subTreeRoot->right_child);
		delete subTreeRoot;
	}
}




