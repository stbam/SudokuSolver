#include "SudokuSolver.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#define M 9
#define N 9
using namespace std;
SudokuSolver::SudokuSolver(){
	solvable=new int*[9];
	for (int i=0;i<9;i++){
		solvable[i]= new int[9];
	}

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			solvable[i][j]=0;
		}
	}


/*	for(int i=0;i<9;i++){
		for (int j=0;j<9;j++){
			std::cout<<solvable[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
*/		
	is_solvable= false;
}

SudokuSolver::SudokuSolver(std::string filen){
//int puzzle[9][9];  // 2D array to store the Sudoku puzzle
    //string filename = "puzzle1.csv";  // name of the CSV file
	is_solvable=false;

	solvable=new int*[9];
	for (int i=0;i<9;i++){
		solvable[i]= new int[9];
	}

    ifstream file(filen);  // open the file for reading
    if (file.is_open()) {
        string line;
        int row = 0;
        while (getline(file, line) && row < 9) {
            stringstream ss(line);
            string x;
            int col = 0;
            while (getline(ss, x, ',') && col < 9) {
               	solvable[row][col] = stoi(x);  // convert string to int
                col++;
            }
            row++;
        }
        file.close();  // close the file
    } 
	/*else {
        cout << "Error: Unable to open file" << endl;
        //return 1;
    }*/
//	solver(solvable);		
	is_solvable=solver();
}

bool SudokuSolver::solver() {
    Sudoku::Location loc = returnNextEmpty();
    if (loc.row == -1 and loc.col==-1)
	 { // if no empty squares, the puzzle is solved
        return true;
    }

    for (int i = 1; i <= 9; i++) { // try every value from 1 to 9 at the current empty square
        if (checkLegalValue(i, loc)) { // if the value is legal, set it and recurse
            solvable[loc.row][loc.col] = i;
            if (solver()) {
                return true; // if the puzzle is solved, return true
            }
	else{
            solvable[loc.row][loc.col] = 0; // undo the previous move
		}
        }
    }

    return false; // if no legal value can be found, backtrack and return false

}



bool SudokuSolver::isPuzzleSolvable(){
	return is_solvable;	
}

int** SudokuSolver:: getPuzzleNumbers(){
	return solvable;	
}
void SudokuSolver::setSolvable(){		
	is_solvable=true;
}

void SudokuSolver::setPuzzleNumbers(int** puzzle){
	**solvable= **puzzle;		
}

Sudoku::Location SudokuSolver::returnNextEmpty(){
Sudoku::Location puzzle;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(solvable[i][j]==0){ // if(arr[i][j]==0){
				puzzle.row=i;
				puzzle.col=j;
				return puzzle;
			}	
		}
	}
	puzzle.row=-1,puzzle.col=-1;
	return puzzle;
}

bool SudokuSolver::checkLegalValue(int value,Sudoku::Location location){
	int row=location.row;
	int col=location.col;		
	bool ROW=true;
	bool COL=true;
	bool GRID=true;

		
	for(int row=0;row<N;row++){
		if(solvable[row][col]==value){
			return false;
		}
	}	

	
	for(int j=0;j<9;j++){
			if(solvable[row][j]==value){
				return false;
			}	
		}

	int subgridrow= row/3;
	int subgridcol=col/3;
	for(int i= subgridrow*3 ; i<subgridrow*3+3;i++){
		for(int j= subgridcol *3;j<subgridcol*3+3;j++){
			if(solvable[i][j]==value){
				return false;
			}	
		}
	}	
	return true;
}

void SudokuSolver::display(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(solvable[i][j]==0){
				cout<<"X"<<" ";
			}
			else if(solvable[i][j]==1 or solvable[i][j]==2 or solvable[i][j]==3 or solvable[i][j]==4 or solvable[i][j]==5 or solvable[i][j]==6 or solvable[i][j]==7 or solvable[i][j]==8 or solvable[i][j]==9){
				cout<<solvable[i][j]<<" ";
			}
		
			if(j==2 or j==5 ){
				cout<<" "<<" "<<"|"<<" ";
			}
		}
				cout<<endl;
					if(i==2 or i==5){
			for(int k=0;k<12;k++){
				cout<<" "<<"-";
			}
			cout<<endl;
		}
	}
}
