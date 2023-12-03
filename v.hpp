#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_
//using namespace std;
#include <string>
#include <vector>
//We define Location within the Sudoku namespace.
//To use Location, you must specify the namespace Sudoku::Location
//Just like you do when using the standard namespace std::
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
SudokuSolver();//const
SudokuSolver(std::string input_file);//param const break down with helper functions
bool isPuzzleSolvable();
void setSolvable();
int getPuzzleNumbers();//returns 2d ptr arr
void setPuzzleNumbers(int** puzzle);
//Utility functions
Sudoku::Location returnNextEmpty();
bool checkLegalValue(int value,Sudoku::Location location);
void display();


private:
//Add your private members here
bool is_solvable;
int **solvable;
int arr[9][9];





};

#endif
