

// This is the "WordTree.h" file

#ifndef	WORDTREE_H		
#define WORDTREE_H
#include <fstream> 
#include <string>

using namespace std;

class WordTree
{
public:
	WordTree();
	void insert(string wrd);
	void findNode(string wrd) const;
	void printInOrder(int num)const;
	~WordTree();

private:
	struct TreeNode
	{
		string word;
		TreeNode* left_child;
		TreeNode* right_child;
		int count;
	};

	void insert(string wrd, struct TreeNode*& subTreeRoot);
	void findNode(string wrd, struct TreeNode* subTreeRoot) const;
	void printInOrder(int num, TreeNode* subTreeRoot, int& count2) const;
	void deleteNodes(TreeNode* node);
	TreeNode* root;
};

#endif
