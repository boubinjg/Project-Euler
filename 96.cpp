#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
#include <limits>
#include <set>
#include <fstream>
#include <sstream>
int count = 0;
void print(std::vector<std::vector<int> > grid)
{
	std::cout<<"GRID"<<std::endl;
	for(int i = 0; i<9; i++)
	{
		for(int j = 0; j<9; j++)
			std::cout<<grid[i][j]<<" ";
		std::cout<<std::endl;
	}
	//count += grid[0][0]*100 + grid[0][1]*10 + grid[0][2];
	//std::cout<<count<<std::endl;
}
bool findULoc(std::vector<std::vector<int> > grid, int &row, int &col)
{
	for(row = 0; row < 9; row++)
		for(col = 0; col<9; col++)
			if(grid[row][col] == 0)
				return true;
	return false;
}
bool usedInRow(std::vector<std::vector<int> > grid, int row, int num)
{
	for(int col = 0; col < 9; col++)
		if(grid[row][col] == num)
			return true;
	return false;
}
bool usedInCol(std::vector<std::vector<int> > grid, int col, int num)
{

	for(int row = 0; row < 9; row++)
		if(grid[row][col] == num)
			return true;
	return false;
}
bool usedInBox(std::vector<std::vector<int> > grid, int bsr, int bsc, int num)
{
	for(int row = 0; row < 3; row++)
		for(int col = 0; col<3; col++)
			if(grid[row+bsr][col+bsc] == num)
				return true;
	return false;
}
bool isSafe(std::vector<std::vector<int> > grid, int row, int col, int num)
{
	return !usedInRow(grid, row, num) &&
	       !usedInCol(grid, col, num) &&
	       !usedInBox(grid,row-row%3, col-col%3, num);
}       
std::vector<std::vector<int> > makegrid(std::vector<std::string> grid)
{
	std::vector<std::vector<int> > igrid;
	for(int i = 0; i<grid.size(); i++)
	{
		std::vector<int> n(9);
		igrid.push_back(n);
		for(int j = 0; j<grid.size(); j++)
		{
			igrid[i][j] = grid[i][j] -'0';	
		}
	}	
	return igrid;
}
bool solve(std::vector<std::vector<int> > grid)
{
	
	int row, col;
	if(!findULoc(grid, row, col))
	{	
		print(grid);
		return true;
	}
	for(int num = 1; num<= 9; num++)
	{
		if(isSafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if(solve(grid)) 
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}
int main()
{
	int count = 0;
	std::ifstream infile("96.txt");
	std::string line;
	std::vector<std::vector<std::string> > grids(50);
	while(std::getline(infile, line))
	{
		if(count % 10 != 0)
		{
			grids[count/10].push_back(line);
		}
		count++;
	}
	for(int i = 0; i<50; i++)
	{
		solve(makegrid(grids[i]));
	}
	return 0;
}
