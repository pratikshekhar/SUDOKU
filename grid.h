/* Header File : grid.h
*/

#ifndef _grid_H_ // If it is not defined
#define _grid_H_ // Define it.

//-------------------------------------------------------------Header Files Used--------------------------------------------------------------------

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------------------------------

class grid
{
private:

	// Private attribute
	vector<vector<int>>sud_;

public:

	// Default Constructor
	grid();

	// Alternate Constructor 
	grid(vector<vector<int>>sud);

	// Destructor 
	~grid();

	
	// Mutators
	void setnum(int row, int col, int num);
	void setrows(int row, vector<int>val);
	

	// Operator overload
	vector<int>operator[] (int num) const;

	// Facilitator
	void toutput(ostream & out); // outputs to a text file
	void soutput(ostream & out); // outputs to the screen 
};
#endif