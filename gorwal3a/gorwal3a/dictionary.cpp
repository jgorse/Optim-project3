#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
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
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		dict.push_back(word);
	}
	cout << "done.\n";
	cout << "Sorting...";
	sort(dict.begin(), dict.end());
	cout << "done.\n";
	file.close();
}

bool dictionary::search(string word)
{
	//my binary search:
	size_t mid, left = 0;
	size_t right = dict.size();
	while (left < right) {
		mid = left + (right - left)/2;
		if (word > dict[mid]){
			left = mid+1;
		}
		else if (word < dict[mid]){                                        
			right = mid;
		}
		else {                                                                  
			return true;
		}                                                                                                               
	}
	return false;

	//sequential search:
	/*int size = dict.size();
	for (int i = 0; i < size; i++)
	{
		if (word == dict[i])
			return true;
	}
	return false;*/

	//standard binary search
	//return binary_search(dict.begin(), dict.end(), word);

}
