/* Name : Pratik Shekhar 
   Program : Sudoku.cpp
 */


//-------------------------------------------------------------Header Files Used--------------------------------------------------------------------


#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include "grid.h"
using namespace std;


//-------------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------Boolean function used in the program to check whether or not puzzle is complete--------------------------------

bool checkrow(grid g1);
bool checkcol(grid g1);

//------------------------------------------------------------------Main Function--------------------------------------------------------------------------

int main()
{
    // output method for saving the data values in a file
	ofstream fout1("output.txt");

   // Prompts the user to enter value
	cout << "enter the text file\n";
	string filename;
	cin >> filename;
	ifstream file(filename.c_str());
	vector<vector<int>> add(9);

	// String variable data to store the values from a text file 
	string data;
	
	for (int i = 0; i < 9; i++)
	{
		file >> data;
		for (int j = 0; j < 9; j++)
		{
			add[i].push_back(data[j] - '0');
		}
	}

	grid g1(add);

	// Display method for producing output with visible gridlines 
	g1.soutput(cout);

	bool input = false;

	// String variable to store the user input
	string line;

	// Integer variable to assign the user input to row, column and number
	int t1, t2, t3;
	while (!input)
	{
		cout << "To enter a number at any position :-\nEnter row value [A-I] first, followed by coloumn value [0-8] and then the number";
		cout << "To exit, press either e or E \n\n";
		cin >> line;
		if (line == "e"|| line=="E") input = true;

		// To check if the user input is correct
		else if (line.length() != 3 || (line[0] - 'A') < 0 || (line[0] - 'A') > 9)
		{ 	
				cout << "Please enter the correct values\n\n";
		}
		else 
		{

			// Converting and ssigning the user input to interger 
			t1 = line[0] - 'A';
			t2 = line[1] - '0';
			t3 = (line[2] - '0')*(-1); // Extra Credit
			
			// To check if the user is tring to override; otherwise it will let user enter the value 
				if (g1[t1][t2] <= 0)
				{
					
					g1.setnum(t1, t2, t3);
					cout << "\n\n\n";
					g1.soutput(cout);
				}
				else
				{
					cout << "You can not override\n\n";
				}
			}	

		// Boolean fuction to check whether or not puzzle is complete 

		if (checkrow(g1) && checkcol(g1))
		{
			g1.toutput(fout1);
			cout << "Congratulations! you have finished the Game Successfully\n";
			input = true;
		}
	}	

	//---------------------------------------------------------End of Program-------------------------------------------------------------------------
}

// Definition of boolean function for rows

bool checkrow(grid g1)
{
	ostringstream os;
	string  chk_line;
	vector<bool>table(9, false);
	for (int row = 0; row < 9;row++)
	{
		int store = 0;
		for (int col = 0; col < 9; col++)
		{
			store = 10 * store + (int)(abs(g1[row][col]));		
		}
		os << store;
		chk_line = os.str();
		os.str("");
		vector<bool>variable(9, false);
		for (int k = 0; k < chk_line.length(); k++)
		{
			if (chk_line[k]!='0')
			{
				variable[chk_line[k] - '0' - 1]=true;
			}
			
		}
		bool random = true;
		for (int IamTired = 0; IamTired <9; IamTired++)
		{
			if (!variable[IamTired])
			{
				
				random = 0;

			}
		}
		table[row] = random;
		
	}
	
	for (int potato = 0; potato < 9; potato++)
	{
		if (!table[potato])
		{
			return false;
		}
		
	}
	return true;
}

// Definition of boolean function for columns 

bool checkcol(grid g1)
{
	ostringstream os;
	string  chk_line;
	vector<bool>table(9, false);
	for (int row = 0; row < 9; row++)
	{
		int store = 0;
		for (int col = 0; col < 9; col++)
		{
			store = 10 * store + (int)(abs(g1[col][row]));

		}

		os << store;
		chk_line = os.str();
		os.str("");
		vector<bool>variable(9, false);
		for (int k = 0; k < chk_line.length(); k++)
		{
			if (chk_line[k] != '0')
			{
				variable[chk_line[k] - '0' - 1] = true;
			}

		}
		bool random = true;
		for (int IamTired = 0; IamTired < 9; IamTired++)
		{
			if (!variable[IamTired])
			{
				random = false;
			}
		}
		table[row] = random;

	}
	for (int potato = 0; potato < 9; potato++)
	{
		if (!table[potato])
		{
			return false;
		}
	}
	return true; 
}
