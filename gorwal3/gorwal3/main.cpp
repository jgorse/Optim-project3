#include "grid.h"
#include <iostream>
#include <string>

using namespace std;
int matches=0;
void searchBase(string baseWord)
{
	if(baseWord.length() <5)
		return;
	string substr="";
	bool match = false;
	for(int i=5; i<16; i++)
	{
		substr = baseWord.substr(0, i);
		
		//match = dict.search(substr);
		//if(match)
		{
			cout<<substr<<"\n";
			matches++;
		}
		if(substr==baseWord)
			break;
	}

	return;
}

void findMatches(grid WordSearch) //Need to pass dictionary too
{
	string baseWord = "";
	string searchTerm = "";
	int row=0, col=0; 

	for(row=0; row<15; row++)
	{
		for(col=0; col<15; col++)
		{
			/***Search right from starting char***/
			int searchcol = col;
			int searchrow = row;
			baseWord = "";
			for(int count = 0; count < 15; count ++)
			{
				if(searchcol == 15)
					searchcol = 0;
				baseWord += WordSearch.puzzle[row][searchcol];
				searchcol++;
			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord);//pass dict too


			/***Search left from starting char***/
			searchcol = col;
			baseWord = "";
			for(int count = 0; count < 15; count ++)
			{
				if(searchcol == -1)
					searchcol = 14;
				baseWord += WordSearch.puzzle[row][searchcol];
				searchcol--;
			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord);//pass dict too



			/***Search up from starting char***/
			searchrow = row;
			baseWord = "";
			for(int count = 0; count < 15; count++)
			{
				if(searchrow == -1)
					searchrow = 14;
				baseWord += WordSearch.puzzle[searchrow][col];
				searchrow--;
			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord);//pass dict too



			/***Search down from starting char***/
			baseWord = "";
			searchrow = row;
			for(int count = 0; count < 15; count++)
			{
				if(searchrow == 15)
					searchrow = 0;
				baseWord += WordSearch.puzzle[searchrow][col];
				searchrow++;
			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord);//pass dict too



			/***Search down-right from starting char***/
			baseWord = "";
			searchrow = row;
			searchcol = col;
			for(int count = 0; count < 15; count++)
			{
				if(searchrow == 15 && searchcol != 15)
				{
					searchrow = abs(row-col);
					searchcol = 0;
				}	
				if(searchcol == 15 && searchrow != 15)
				{
					searchcol = abs(row-col);
					searchrow = 0;
				}
				if(searchcol == 15 && searchrow == 15)
				{
					searchcol = searchrow = 0;
				}
				
				if(searchrow == row && searchcol == col && baseWord != "")
					break;

				baseWord += WordSearch.puzzle[searchrow][searchcol];
				searchrow++;
				searchcol++;

				
			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord);//pass dict too


			/***Search up-left from starting char***/
			baseWord = "";
			searchrow = row;
			searchcol = col;
			for(int count = 0; count < 15; count++)
			{
				if(searchrow == -1 && searchcol != -1)
				{
					searchrow = 14-col+row;
					searchcol = 14;
				}	
				if(searchcol == -1 && searchrow != -1)
				{
					searchcol = 14-row+col;
					searchrow = 14;
				}
				if(searchcol == -1 && searchrow == -1)
				{
					searchrow = 14;
					searchcol = 14;
				}
				
				if(searchrow == row && searchcol == col && baseWord != "")
					break;

				baseWord += WordSearch.puzzle[searchrow][searchcol];
				searchrow--;
				searchcol--;

			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord);//pass dict too

			/***Search up-right from starting char***/
			baseWord = "";
			searchrow = row;
			searchcol = col;
			for(int count = 0; count < 15; count++)
			{
				if(searchrow == -1 && searchcol != 15)
				{
					searchrow = row+col;
					searchcol = 0;
				}	
				if(searchcol == 15 && searchrow != -1)
				{
					searchcol = searchrow+1;
					searchrow = 14;
				}
				if(searchcol == 15 && searchrow == -1)
				{
					searchrow = 14;
					searchcol = 0;
				}
				
				if(searchrow == row && searchcol == col && baseWord != "")
					break;

				baseWord += WordSearch.puzzle[searchrow][searchcol];
				searchrow--;
				searchcol++;

			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord);//pass dict too


			/***Search down-left from starting char***/
			baseWord = "";
			searchrow = row;
			searchcol = col;
			for(int count = 0; count < 15; count++)
			{
				if(searchrow == 15 && searchcol != -1)
				{
					searchrow = searchcol+1;
					searchcol = 14;
				}	
				if(searchcol == -1 && searchrow != 15)
				{
					searchcol = row+col;
					searchrow = 0;
				}
				if(searchcol == -1 && searchrow == 15)
				{
					searchrow = 0;
					searchcol = 14;
				}
				
				if(searchrow == row && searchcol == col && baseWord != "")
					break;

				baseWord += WordSearch.puzzle[searchrow][searchcol];
				searchrow++;
				searchcol--;

			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord);//pass dict too

		}
	}

}

void testSearch()
{
	string filename = "input15.txt";
	//cout<<"Enter filename for grid: ";
	//cin>>filename;

	grid puzzle(filename);

	if(puzzle.success == false)
	{
		cout<<"Could not load Wordsearch grid.\n";
		return;
	}

	//dictionary dict;

	findMatches(puzzle);//pass dict too
}

int main()
{
	testSearch();
	cout<<"Matches found: "<<matches<<"\n";
	system("pause");
	return 0;
}