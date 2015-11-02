/* Cpp File : grid.cpp 
*/

//-------------------------------------------------------------Header Files Used--------------------------------------------------------------------

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cmath>
#include "grid.h"
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Default Constructor

grid::grid()
{
	vector<int> default(9, 0);
	for (int i = 1; i <= 9; i++)
	{
		sud_.push_back(default);
	}
}

// Alternate Constructor 

grid::grid(vector<vector<int>>sud)
{
	sud_ = sud;
}

// Destructor 

grid::~grid()
{
// Empty destructor;
}

// Operator overload

vector<int> grid::operator[] (int num) const
{
	return sud_[num];
}

// Mutators
void grid::setnum(int row, int col, int num)
{
	// Extra Credit
	int row_value, col_value,temp;
	row_value = row-(row%3);
	col_value = col - (col % 3);
	for (int m = row_value; m < row_value + 3;m++)
	{
		for (int n = col_value; n < col_value + 3; n++)
		{
			if (sud_[m][n] == abs(num))
			{
				num = 0;
				sud_[row][col] = num; 
				//cout << "The number already is present in the block\n";
			}
			
		}
	}
	// Extra Credit
	for (int i = 0; i < 9; i++)
	{
		if (sud_[row][i] == abs(num) || sud_[i][col] == abs(num))
		{
						//cout << "You have inserted Wrong Number\n";
			num = 0;
			sud_[row][col] = num;
			//cout << "The number already is present either in this row or column\n";
		}
		
		else
		{
			sud_[row][col] = num;
		}
		//cout << "You have inserted Wrong Number\n";
	}
	
	// sud_[row][col] = num;
}

// Mutators

void grid::setrows(int row, vector<int>val)
{
	sud_[row] = val;
}

// Facilitator :- outputs to a text file

void grid::toutput(ostream & out)
{
	out << "    0 1 2   3 4 5   6 7 8  \n";
	out << "  +-------+-------+-------+\n";
	vector<char>element;
	element.push_back('A');
	element.push_back('B');
	element.push_back('C');
	element.push_back('D');
	element.push_back('E');
	element.push_back('F');
	element.push_back('G');
	element.push_back('H');
	element.push_back('I');
	for (int row = 0; row < 9;row++)
	{
		out << element[row] << " | ";
		for (int col = 0; col <9; col++)
		{
			out << abs(sud_[row][col]);
			out << " ";
			if ((col + 1) % 3 == 0)
			{
				out << "| ";
			}
		}
		out << "\n";
		if ((row + 1) % 3 == 0)
		{
			out << "  +-------+-------+-------+\n";
		}
	}
}

// Facilitator :- outputs to the screen

void grid::soutput(ostream & out)
{
	out << "    0 1 2   3 4 5   6 7 8  \n";
	out << "  +-------+-------+-------+\n";
	vector<char>element;	
	element.push_back('A');
	element.push_back('B');
	element.push_back('C');
	element.push_back('D');
	element.push_back('E');
	element.push_back('F');
	element.push_back('G');
	element.push_back('H');
	element.push_back('I');
	for (int row = 0; row < 9; row++)
	{
		out << element[row] << " | ";
		for (int col = 0; col < 9; col++)
		{
			//int blank;
			if (sud_[row][col]==0)
			{
				out << "-";
			}
			else out << abs(sud_[row][col]);
			out << " ";
			if ((col+1)%3==0)
			{
				out << "| ";
			}
		}
		out << "\n";
		if ((row+1)%3==0)
		{
			out << "  +-------+-------+-------+\n";
		}
	}


}

