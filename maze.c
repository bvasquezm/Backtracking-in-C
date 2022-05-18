// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

// C++ program to solve common Maze problem using
// backtracking
#include <stdio.h>
#include <stdbool.h>
// Maze size
#define N 4

// Starting point
#define X0 1
#define Y0 2

// Goal
#define XF 3
#define YF 3

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

// A utility function to print solution matrix sol[N][N]
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

// A utility function to check if x, y is valid index for
// N*N maze
bool isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;
	return false;
}

bool checkGoal(int x, int y, int maze[N][N]) 
{
	if (x == XF && y == YF && maze[x][y] == 1)
		return true;
	return false;
}

// This function solves the Maze problem using Backtracking.
// It mainly uses solveMazeUtil() to solve the problem. It
// returns false if no path is possible, otherwise return
// true and prints the path in the form of 1s. Please note
// that there may be more than one solutions, this function
// prints one of the feasible solutions.
bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { 	{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } 	};
	if (solveMazeUtil(maze, X0, Y0, sol) == false) {
		printf("Solution doesn't exist\n");
		return false;
	}
	printSolution(sol);
	return true;
}

// A recursive utility function to solve Maze problem
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	// if (x, y is goal) return true
	if (checkGoal(x, y, maze) == true) {
		sol[x][y] = 1;
		return true;
	}
	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y) == true) {
		// Check if the current block is already part of
		// solution path.
		if (sol[x][y] == 1)
			return false;
		// mark x, y as part of solution path
		sol[x][y] = 1;

		// SOUTH
		if (solveMazeUtil(maze, x + 1, y, sol) == true)
			return true;
		// EAST
		if (solveMazeUtil(maze, x, y + 1, sol) == true)
			return true;
		// NORTH
		if (solveMazeUtil(maze, x - 1, y, sol) == true)
			return true;
		// WEST
		if (solveMazeUtil(maze, x, y - 1, sol) == true)
			return true;
			
		// If none of the above movements work then
		// BACKTRACK: unmark x, y as part of solution path
		sol[x][y] = 0;
		return false;
	}
	return false;
}

// driver program to test above function {1: Path | 0: Wall}
int main()
{
	int maze[N][N] = {	{ 0, 0, 0, 0 },
						{ 1, 1, 1, 1 },
						{ 0, 1, 0, 0 },
						{ 1, 1, 1, 1 } 	};
	solveMaze(maze);
	return 0;
}

// Base code is contributed by Aditya Kumar (adityakumar129)