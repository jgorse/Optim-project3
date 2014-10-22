#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "dictionary.h"

using namespace std;

dictionary::dictionary()
{
	ifstream file;
	string filename = "dictionary.txt";
	string word;
	file.open(filename);
	if (!file)
		cout << "Error: File not found.\n";
	cout << "Reading dictionary...";
	while (!file.eof())
	{
		file >> word;
		dict.push_back(word);
	}
	cout << "done.\n";
	file.close();
}

bool dictionary::search(string word)
{
	int size = dict.size();
	for (int i = 0; i < size; i++)
	{
		if (word == dict[i])
			return true;
	}
	return false;
}