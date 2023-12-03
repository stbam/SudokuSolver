#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_
//using namespace std;
#include <string>
#include <vector>
//We define Location within the Sudoku namespace.
//To use Location, you must specify the namespace Sudoku::Location
//Just like you do when using the standard namespace std::
/*
Location (provided with the starter files) is a struct that consists of 2 integers, a row index and a column index representing a square within the 9x9 grid of the sudoku puzzle. We start from index 0, as usual, so the possible values for row and column are 0-8. 0,0 is the top left square of the board, 0,8 is the top right, 8,0 is bottom left, and 8,8 is be the bottom right square. Note that this is inside the namespace Sudoku. You have dealt with namespaces plenty of times, specifically the standard namespace std. When using the standard library you use std:: followed by the object, for example, std::cout or std::vector. When using Location you need to do the same thing, Sudoku::Location , using the Sudoku:: namespace. 
*/
namespace Sudoku
{ 
  struct Location
  {
    int row;
    int col;
  };

}

class SudokuSolver
{
public:


 
//Add your public members here
SudokuSolver();//default constt
SudokuSolver(std::string input_file);//param const break down with helper functions
bool isPuzzleSolvable();//returns true if puzzle has a solution
void setSolvable();//sets solvable to true
// int getPuzzleNumbers();//returns 2d ptr arr
int** getPuzzleNumbers();
void setPuzzleNumbers(int** puzzle);
//Utility functions
Sudoku::Location returnNextEmpty();//finds next empty location on board and returns it
bool checkLegalValue(int value,Sudoku::Location location);//checks if the value can be placed according to sudoku rules
void display();//displays for the user the puzzle

//bool solver(int** puzzle);


private:
//Add your private members here
bool is_solvable;
int **solvable;//2d array


//int arr[9][9];





};

#endif
