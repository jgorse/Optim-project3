#include <iostream>
#include <vector>

using namespace std;

class dictionary
{
public:
	vector<string> dict;
	dictionary();
	bool search(string word);
	void quickSort(int left, int right);
};