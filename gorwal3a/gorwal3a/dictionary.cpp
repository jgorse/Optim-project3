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

	//Open dictionary file
	file.open(filename);
	if (!file)
		cout << "Error: File not found.\n";

	//Read dictionary file into vector
	cout << "Reading dictionary...";
	while (!file.eof())
	{
		file >> word;
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		dict.push_back(word);
	}
	cout << "done.\n";
	file.close();

	//sort vector
	cout<<"Sorting dictionary...";
	//sort(dict.begin(), dict.end()); //This is the std sort method in <algorithm>
	quickSort(0, dict.size()-1);; //This is the quicksort implemented by us
	cout<<"done.\n";

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

void dictionary::quickSort(int left, int right)
{
    int i = left, j = right;
    string tmp;
    string pivot = dict[(left + right) / 2]; //middle element

    //partition
    while( i <= j ) 
	{
        while ((dict[i]).compare(pivot) < 0) 
		{
            i++;
        }
        while ((dict[j]).compare(pivot) > 0) 
		{
            j--;
        }
        if ( i <= j ) 
		{
            tmp = dict[i];
            dict[i] = dict[j];
            dict[j] = tmp;
            i++;
            j--;
        }
    }

    //recursion
    if ( left < j ) 
	{
        quickSort(left, j);
    }
    if ( i < right ) 
	{
        quickSort(i, right);
    }

}
