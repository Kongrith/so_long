/*
https://github.com/MananAg29/Rat-in-a-Maze/blob/main/Rat_in_a_Maze.c
*/

#include <stdio.h>

// Maze size
#define N 4
#define false 0
#define true 1

int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

int isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;

	return false;
}

/* This function solves the Maze problem using Backtracking. It mainly
uses solveMazeUtil() to solve the problem. It returns false if no
path is possible, otherwise return true and prints the path in the
form of 1s.*/
int solveMaze(int maze[N][N])
{
	int sol[N][N] = {{0, 0, 0, 0},
					 {0, 0, 0, 0},
					 {0, 0, 0, 0},
					 {0, 0, 0, 0}};

	if (solveMazeUtil(maze, 0, 0, sol) == false)
	{
		printf("Solution doesn't exist");
		return false;
	}

	printSolution(sol);
	return true;
}

/* A recursive utility function to solve Maze problem */
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	// if (x, y is goal) return true
	if (x == N - 1 && y == N - 1)
	{
		sol[x][y] = 1;
		return true;
	}
	if (isSafe(maze, x, y) == true)
	{
		sol[x][y] = 1;
		if (solveMazeUtil(maze, x + 1, y, sol) == true)
			return true;
		if (solveMazeUtil(maze, x, y + 1, sol) == true)
			return true;
		sol[x][y] = 0;
		return false;
	}

	return(false);
}

int main()
{
	int maze[N][N] = {{1, 0, 0, 0},
					  {1, 1, 0, 1},
					  {0, 1, 0, 0},
					  {1, 1, 1, 1}};

	solveMaze(maze);
	return 0;
}
