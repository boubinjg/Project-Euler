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
//contains Hs
std::vector<std::vector<int> > map;
//contains Fs
std::vector<int> costList(6400);
std::vector<std::vector<int> > adjacencyList;
int h(int n)
{
	int i = n/80;
	int j = n%80;
	return (80-i) * (80-j);
}
int leastCost(std::vector<int> open, std::vector<int> f)
{
	int min = -1, minVal = INT_MAX;
	int n = 0;
	for(int i = 0; i<open.size(); i++)
	{
		n = f[open[i]];
		if(n<minVal)
		{
			min = i;
			minVal = n;
		}
	}
	return min;
}
int reconstruct(std::vector<int> cameFrom, int current)
{
	//std::cout<<current<<std::endl;
	int count = 0;
	count += map[current/80][current%80];
	while(current != 0)
	{
		current = cameFrom[current];
	//	std::cout<<current<<std::endl;
		count += map[current/80][current%80];
	}
	return count;
}
int astar(std::vector<std::vector<int> > list)
{
	int start = 0;
	int goal = 6400;
	std::vector<int> open;
	std::vector<int> closed;
	std::vector<int> cameFrom(6400);
	
	std::vector<int> gScore(6400);
	std::fill(gScore.begin(), gScore.end(), INT_MAX);
	gScore[start] = map[0/80][0%80];
	
	std::vector<int> fScore(6400);
	std::fill(fScore.begin(), fScore.end(), INT_MAX);
	fScore[start] = h(0);

	open.push_back(0);
	int count = 0;
	while(open.size() > 0 /*count < 10*/)
	{
		//std::cout<<"start loop"<<std::endl;
		int pos = leastCost(open, fScore), tg = 0, child = 0, cur = 0;
		cur = open[pos];
		if(cur == 6399)
		{
			std::cout<<"found"<<std::endl;
			return reconstruct(cameFrom, cur);
		}
		//std::cout<<pos<<std::endl;
		open.erase(open.begin() + pos);
		closed.push_back(cur);
	
		for(int i = 0; i<adjacencyList[cur].size(); i++)
		{	
			child = adjacencyList[cur][i];
			if(std::find(closed.begin(), closed.end(), child) != closed.end())
				continue;
				
			tg = gScore[cur] + map[child/80][child%80];
			
			if(std::find(open.begin(), open.end(), child) == open.end())	
				open.push_back(child);
			if(tg >= gScore[child])
				continue;

			cameFrom[child] = cur;
			gScore[child] = tg;
			fScore[child] = gScore[child] + h(child);
			//std::cout<<fScore[child]<<std::endl;
		}
	}
	//reconstruct(cameFrom);
	return -1;
}

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
	for(int i = 0; i<map.size(); i++)
	{
		for(int j = 0; j<map.size(); j++)
		{
			std::vector<int> s;
			if(j<map.size()-1)
				s.push_back(i*80 + j+1);
			if(j>0)
				s.push_back(i*80 + j-1);
			if(i<map.size()-1)
				s.push_back((i+1)*80 + j);
			if(i>0)
				s.push_back(80*(i-1)+j);
			adjacencyList.push_back(s);
		}
	}
	std::cout<<astar(adjacencyList)<<std::endl;;
}
