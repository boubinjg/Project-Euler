#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <sstream>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
#include <limits.h>
#define V 6400
void printMap(std::vector<std::vector<int> > m)
{
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<5; j++)
		{
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
int main()
{
	std::vector<std::vector<int> > map;
	std::ifstream myfile("81.txt");
	std::string line;
	while(myfile)
	{
		if(!getline(myfile,line)) break;
		std::istringstream ss(line);
		std::vector<int> r;
		while(ss)
		{
			std::string s;
			if(!getline(ss,s,',')) break;
				r.push_back(std::stoi(s));
		}
		map.push_back(r);
	}
	printMap(map);
	std::cout<<std::endl;
	for(int i = map.size()-2; i>=0; i--)
	{
			map[map.size()-1][i] += map[map.size()-1][i+1];
			map[i][map.size()-1] += map[i+1][map.size()-1];
	}
	for(int i = map.size()-2; i>=0; i--)
	{
		for(int j = map.size()-2; j>=0; j--)
		{
			map[i][j] += std::min(map[i+1][j], map[i][j+1]);
		}
	}
	
	printMap(map);
	std::cout<<map[0][0]<<std::endl;
}



