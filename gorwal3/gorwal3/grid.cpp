#include <string>
#include "grid.h"

using namespace std;

grid::grid(string filename)
{
	puzzle.resize(15,15);
	success = false;

	ifstream fin;
	fin.open(filename.c_str());
	if(!fin)
	{
		cout<<"Could not open file!\n";
		return;
	}
	char x;

	//read first 4 characters (size of grid)
	for(int i=0; i<4; i++)
	{
		if(!fin.eof())
		{
			fin>>x;
		}
	}

	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
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