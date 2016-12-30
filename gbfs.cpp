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
void print(std::vector<std::vector<int> > v)
{
	for(int i = 0; i<v.size(); i++)
	{
		std::cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<std::endl;
	}
}
int evaluation(std::vector<std::vector<int> > choices)
{
	int min = INT_MAX, pos = 0;
	for(int i = 0; i<choices.size(); i++)
	{
		if(choices[i][2] < min)
		{
			pos = i;
			min = choices[i][2];
		}
	}
	std::cout<<min<<std::endl;
	return pos;
}
int bfs(std::vector<std::vector<int> > map)
{
	std::vector<std::vector<int> > queue; 
	std::vector<int> f(3);
	f[2] = map[0][0];
	queue.push_back(f);
	int count = 0;
	int best = evaluation(queue);
	int xpos, ypos;
	while(queue[best][0] < map.size()-1 || queue[best][1] < map.size()-1)
	{
		
		xpos = queue[best][0];
		ypos = queue[best][1];
		if(xpos < map.size()-1)
		{
			std::vector<int> sto;
			sto.push_back(xpos+1);
			sto.push_back(ypos);
			sto.push_back(map[xpos+1][ypos]+ queue[best][2]);
			queue.push_back(sto);
		}
		if(ypos < map.size()-1)
		{
			std::vector<int> sto;
			sto.push_back(xpos);
			sto.push_back(ypos+1);
			sto.push_back(map[xpos][ypos+1] + queue[best][2]);
			queue.push_back(sto);
		}
		queue.erase(queue.begin() + best);
		//print(queue);
		best = evaluation(queue);
		count++;
	}
	return queue[best][2];
}
void printMap(std::vector<std::vector<int> > map)
{
	for(int i = 0; i<map.size(); i++)
	{
		for(int j = 0; j<map.size(); j++)
		{
			std::cout<<map[i][j]<<" ";
		}
		std::cout<<std::endl;
	}	
}
int main()
{
	std::vector<std::vector<int> > map;
	std::ifstream myfile("81test.txt");
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
	//printMap(map);
	std::cout<<bfs(map)<<std::endl;
}



