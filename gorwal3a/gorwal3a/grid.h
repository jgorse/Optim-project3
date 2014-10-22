#include <istream>
#include <fstream>
#include <string>
#include "d_matrix.h"

using namespace std;

#ifndef GRID_H
#define GRID_H

class grid
{	
	
public:
	grid(string filename);
	bool success;
	matrix<char> puzzle;
	int size;
};

#endif //GRID_H