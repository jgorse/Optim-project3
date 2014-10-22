#include "grid.h"
#include "dictionary.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
int matches=0;
int gridsize=0;
clock_t starttime;
clock_t endtime;

void searchBase(string baseWord, dictionary dict)
{
	if(baseWord.length() <5)
		return;
	string substr="";
	bool match = false;
	for(int i=5; i<gridsize+1; i++)
	{
		substr = baseWord.substr(0, i);
		
		match = dict.search(substr);
		if(match)
		{
			cout<<substr<<"\n";
			matches++;
		}
		if(substr==baseWord)
			break;
	}

	return;
}

void findMatches(grid WordSearch, dictionary dict) //Need to pass dictionary too
{
	string baseWord = "";
	string searchTerm = "";
	int row=0, col=0; 
	gridsize = WordSearch.size;

	cout << "Doing wordsearch, matching strings found so far: \n";
	for(row=0; row<WordSearch.size; row++)
	{
		for(col=0; col<WordSearch.size; col++)
		{
			/***Search right from starting char***/
			int searchcol = col;
			int searchrow = row;
			baseWord = "";
			for(int count = 0; count < WordSearch.size; count ++)
			{
				if(searchcol == WordSearch.size)
					searchcol = 0;
				baseWord += WordSearch.puzzle[row][searchcol];
				searchcol++;
			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord, dict);//pass dict too


			/***Search left from starting char***/
			searchcol = col;
			baseWord = "";
			for(int count = 0; count < WordSearch.size; count ++)
			{
				if(searchcol == -1)
					searchcol = WordSearch.size-1;
				baseWord += WordSearch.puzzle[row][searchcol];
				searchcol--;
			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord, dict);//pass dict too



			/***Search up from starting char***/
			searchrow = row;
			baseWord = "";
			for(int count = 0; count < WordSearch.size; count++)
			{
				if(searchrow == -1)
					searchrow = WordSearch.size-1;
				baseWord += WordSearch.puzzle[searchrow][col];
				searchrow--;
			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord, dict);//pass dict too



			/***Search down from starting char***/
			baseWord = "";
			searchrow = row;
			for(int count = 0; count < WordSearch.size; count++)
			{
				if(searchrow == WordSearch.size)
					searchrow = 0;
				baseWord += WordSearch.puzzle[searchrow][col];
				searchrow++;
			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord, dict);//pass dict too



			/***Search down-right from starting char***/
			baseWord = "";
			searchrow = row;
			searchcol = col;
			for(int count = 0; count < WordSearch.size; count++)
			{
				if(searchrow == WordSearch.size && searchcol != WordSearch.size)
				{
					searchrow = abs(row-col);
					searchcol = 0;
				}	
				if(searchcol == WordSearch.size && searchrow != WordSearch.size)
				{
					searchcol = abs(row-col);
					searchrow = 0;
				}
				if(searchcol == WordSearch.size && searchrow == WordSearch.size)
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
			searchBase(baseWord, dict);//pass dict too


			/***Search up-left from starting char***/
			baseWord = "";
			searchrow = row;
			searchcol = col;
			for(int count = 0; count < WordSearch.size; count++)
			{
				if(searchrow == -1 && searchcol != -1)
				{
					searchrow = WordSearch.size-1-col+row;
					searchcol = WordSearch.size-1;
				}	
				if(searchcol == -1 && searchrow != -1)
				{
					searchcol = WordSearch.size-1-row+col;
					searchrow = WordSearch.size-1;
				}
				if(searchcol == -1 && searchrow == -1)
				{
					searchrow = WordSearch.size-1;
					searchcol = WordSearch.size-1;
				}
				
				if(searchrow == row && searchcol == col && baseWord != "")
					break;

				baseWord += WordSearch.puzzle[searchrow][searchcol];
				searchrow--;
				searchcol--;

			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord, dict);//pass dict too

			/***Search up-right from starting char***/
			baseWord = "";
			searchrow = row;
			searchcol = col;
			for(int count = 0; count < WordSearch.size; count++)
			{
				if(searchrow == -1 && searchcol != WordSearch.size)
				{
					searchrow = row+col;
					searchcol = 0;
				}	
				if(searchcol == WordSearch.size && searchrow != -1)
				{
					searchcol = searchrow+1;
					searchrow = WordSearch.size-1;
				}
				if(searchcol == WordSearch.size && searchrow == -1)
				{
					searchrow = WordSearch.size-1;
					searchcol = 0;
				}
				
				if(searchrow == row && searchcol == col && baseWord != "")
					break;

				baseWord += WordSearch.puzzle[searchrow][searchcol];
				searchrow--;
				searchcol++;

			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord, dict);//pass dict too


			/***Search down-left from starting char***/
			baseWord = "";
			searchrow = row;
			searchcol = col;
			for(int count = 0; count < WordSearch.size; count++)
			{
				if(searchrow == WordSearch.size && searchcol != -1)
				{
					searchrow = searchcol+1;
					searchcol = WordSearch.size-1;
				}	
				if(searchcol == -1 && searchrow != WordSearch.size)
				{
					searchcol = row+col;
					searchrow = 0;
				}
				if(searchcol == -1 && searchrow == WordSearch.size)
				{
					searchrow = 0;
					searchcol = WordSearch.size-1;
				}
				
				if(searchrow == row && searchcol == col && baseWord != "")
					break;

				baseWord += WordSearch.puzzle[searchrow][searchcol];
				searchrow++;
				searchcol--;

			}
			//cout<<baseWord<<"\n";
			searchBase(baseWord, dict);//pass dict too

		}
	}

}

void testSearch()
{
	string filename;// = "input30.txt";
	cout<<"Enter filename for grid: ";
	cin>>filename;

	starttime = clock();

	grid puzzle(filename);

	if(puzzle.success == false)
	{
		cout<<"Could not load Wordsearch grid.\n";
		return;
	}

	dictionary dict;

	findMatches(puzzle, dict);//pass dict too
}

int main()
{
	testSearch();
	cout<<"Matches found: "<<matches<<"\n";

	endtime = clock();
    cout << "Time required for execution: "
    << (double)(endtime-starttime)/CLOCKS_PER_SEC
    << " seconds." << "\n\n";

	system("pause");
	return 0;
}