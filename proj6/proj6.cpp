// language: C++
// author: Vanessa Serao



#include "wordtree.h"
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>
#include <vector>
using namespace std;


int main()
{
	string text;
	int num = 4;
	vector<string> V;
	ifstream inFile;
	inFile.open("input.txt");

	WordTree Tree;

	if (!"input.txt")
	{
		cerr << "File not found" << endl;
		exit(1);
	}
	
	getline(inFile, text);
	std::transform(text.begin(), text.end(), text.begin(), ::tolower);// transform all words to lower 
	
	
	// push words from text into the vector 
	std::size_t pos = 0, found;
	while ((found = text.find_first_of(' ', pos)) != std::string::npos)
	{
		V.push_back(text.substr(pos, found - pos));
		pos = found + 1;
	}
	V.push_back(text.substr(pos));
	
	//Create tree from vector
	for (int i = 0; i < V.size(); i++)
	{
		Tree.insert(V[i]);
	}
	
	cout << "Word tree built and loaded\n\n";
	cout << "Finding all words with " << num << " or more occurrences:" << endl;
	Tree.printInOrder(num);
	
	cout << endl;
	cout << "Searching for occurrances of the word 'query'\n";
	Tree.findNode("query");
	cout << endl;
	
	cout << "Searching for occurrances of the word 'stack'\n";
	Tree.findNode("stack");
	inFile.close();
	
	system("pause");
	return 0;
}
