#include <string>
#include "grid.h"

using namespace std;

grid::grid(string filename)
{
	
	success = false;

	ifstream fin;
	fin.open(filename.c_str());
	if(!fin)
	{
		cout<<"Could not open file!\n";
		return;
	}
	char x;
	string s="";

	//read first 4 characters (size of grid)
	for(int i=0; i<4; i++)
	{
		if(!fin.eof())
		{
			fin>>x;
			s+=x;
		}
	}
	s=s.substr(0,2);
	size = (s[0]-48)*10 + (s[1]-48);

	puzzle.resize(size,size);
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(!fin.eof())
			{
				fin>>x;
				puzzle[i][j] = x;
			}
		}
	}

	success = true;
	

}