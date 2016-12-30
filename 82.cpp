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
		for(int j = 0; j<4; j++)
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
	
	int ms = map.size();
	std::vector<int> s(ms);
	for(int i = 0; i<ms; i++)
	{
		s[i] = map[i][ms-1];
	}
	for(int i = ms-2; i>=0; i--)
	{
		s[0] += map[0][i];
		for(int j = 1; j<ms; j++)
		{
			s[j] = std::min(s[j-1] + map[j][i], s[j] + map[j][i]);
		}
		
		for(int j = ms - 2; j>= 0; j--)
		{
			s[j] = std::min(s[j], s[j+1] + map[j][i]);
		}
	}
	int min = INT_MAX;
	for(int i = 0; i<ms; i++)
	{
		if(s[i] < min)
			min = s[i];
	}
	std::cout<<min<<std::endl;
}



