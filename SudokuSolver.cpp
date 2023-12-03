#include "SudokuSolver.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#define M 9
#define N 9
using namespace std;

SudokuSolver::SudokuSolver(){
	solvable=new int*[9];//creates an array of 9
	for (int i=0;i<9;i++){
		solvable[i]= new int[9];//duplicates the array of 9, 9 times
	}

	for(int i=0;i<9;i++){//fills the array of 9x9 with 0's
		for(int j=0;j<N;j++){
			solvable[i][j]=0;
		}
	}


	is_solvable= false; //sets private variable to false as default
}

bool solver() {//helper function used to implement the backgracking algorithm
    Sudoku::Location loc = returnNextEmpty();
    if (loc.row == -1 && loc.col == -1) { // 
        return true;
    }
    for (int i = 1; i <10; i++) {  
        if (checkLegalValue(i, loc)) {  //checks if the value is legal 
            solvable[loc.row][loc.col] = i; //if it is set i to that lco
            if (solver()) {//recursive if true
                return true;  
            }
            solvable[loc.row][loc.col] = 0; //if not true set back to 0
        }
    }
    return false;  
}

SudokuSolver::SudokuSolver(std::string filen){
//int puzzle[9][9];  // 2D array to store the Sudoku puzzle
    //string filename = "puzzle1.csv";  // name of the CSV file
	is_solvable=false;

	solvable=new int*[9];
	for (int i=0;i<9;i++){
		solvable[i]= new int[9];
	}

    ifstream file(filen);  // opens the file to read its contents
    if (file.is_open()) {
        string line;
	string box;
        int row = 0;
        while (getline(file, line) && row < M) {
            stringstream ss(line);
            
            int col = 0;
            while (getline(ss, box, ',') && col < M) {
               	solvable[row][col] = stoi(box);  // converts string to int for each row one by one
                col++;
            }
            row++;
        }
        file.close();  // close the file
    } 
bool trueorfalse=solver();
	
	is_solvable=trueorfalse;
}





bool SudokuSolver::isPuzzleSolvable(){
	return is_solvable;//returns bool that is set in default and param cosnt	
}

int** SudokuSolver:: getPuzzleNumbers(){
	return solvable;//returns the ptr from default cosnt	to be accessible by other funcs ass needed
}
void SudokuSolver::setSolvable(){		
	is_solvable=true;//sets is_solvable private member to true when called
}

void SudokuSolver::setPuzzleNumbers(int** puzzle){
	**solvable= **puzzle;	//sets solvable to puzzle 2d meant to overwrite	
}

Sudoku::Location SudokuSolver::returnNextEmpty(){
Sudoku::Location puzzle;//create location called puzzle
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
	int row=location.row; //location.row and col set to row and col
	int col=location.col;		
	bool ROW=true;//bool values turned out to be useless
	bool COL=true;
	bool GRID=true;

		
	for(int row=0;row<N;row++){
		if(solvable[row][col]==value){//iterates through row looking for value if found return false
			return false;
		}
	}	

	
	for(int j=0;j<N;j++){
			if(solvable[row][j]==value){//iterates through col same as above
				return false;
			}	
		}

	int subgridrow= row/3;//row of 9 divide by 3 makes a 3 by 3 row col
	int subgridcol=col/3;
	subgridrow=subgridrow*3;//
	subgridcol=subgridcol*3;	
	for(int i= subgridrow; i<subgridrow+3;i++){
		for(int j= subgridcol;j<subgridcol+3;j++){
			if(solvable[i][j]==value){//iterates through each j col checking for given val in the 3x3 grind
				return false;
			}	
		}	
	}	
	return true;
}

void SudokuSolver::display(){//display function made according to specs returns nothing
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
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

