#include <iostream>
using namespace std;

const int SIZE = 9;


void printGrid(int grid[SIZE][SIZE])		// Function to print the Sudoku grid
{
    cout << "\nSolved Sudoku:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


bool isRowSafe(int grid[SIZE][SIZE], int row, int num)		// Check if number is safe in row
{
    for (int col = 0; col < SIZE; col++)
    {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}


bool isColSafe(int grid[SIZE][SIZE], int col, int num)		// Check if number is safe in column
{
    for (int row = 0; row < SIZE; row++)
    {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}


bool isBoxSafe(int grid[SIZE][SIZE], int startRow, int startCol, int num)		// Check if number is safe in 3x3 subgrid
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}


bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)		// Check if it's safe to place number
{
    return isRowSafe(grid, row, num) &&
           isColSafe(grid, col, num) &&
           isBoxSafe(grid, row - row % 3, col - col % 3, num);
}


bool solveSudoku(int grid[SIZE][SIZE])			// Main backtracking function
{
    int row = -1, col = -1;
    bool isEmpty = false;

    // Find an empty cell (represented by 0)
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }

    // If no empty cell found, Sudoku is solved
    if (!isEmpty)
        return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;  // Place number

            if (solveSudoku(grid)) // Recursive call
                return true;

            grid[row][col] = 0;    // Backtrack
        }
    }

    return false; // This trigger backtracking
}

int main()
{
    int grid[SIZE][SIZE];

    cout << "Enter Sudoku (use 0 for empty cells):\n";

    // Input grid
    for (int i = 0; i < SIZE; i++)
    {
    	cout<<"For Row number "<<i+1<<": "<<endl;
        for (int j = 0; j < SIZE; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Solve Sudoku
    if (solveSudoku(grid))
    {
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists!\n";
    }

    return 0;
}
