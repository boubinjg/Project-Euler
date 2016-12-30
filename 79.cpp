#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
void print(std::vector<char> c)
{
	for(int i = 0; i<c.size(); i++)
	{
		std::cout<<c[i]<<std::endl;
	}
}
int main()
{	
	std::vector<std::string> keylog;
	std::string line;
	std::fstream myfile("79.txt");
	if(myfile.is_open())
	{
		while(std::getline(myfile,line))
		{
			keylog.push_back(line);
		}
		myfile.close();
	}
	std::vector<char> s;
	std::vector<char> first;
	char cur;
	int pos = 0;
	for(int c = 0; c<9; c++)
	{
		cur = '-';
		for(int i = 0; i<keylog.size(); i++)
		{
			for(int j = pos+1; j<3; j++)
			{
				if(cur == '-' && std::find(s.begin(), s.end(), keylog[i][pos]) == s.end())
					cur = keylog[i][pos];
				if(cur == keylog[i][j] && std::find(s.begin(), s.end(), keylog[i][pos]) == s.end())
					cur = keylog[i][pos];
			}
		}
		if(cur == '-')
		{
			pos++;
		}
		else
			s.push_back(cur);
	}
	for(int i = 0; i<keylog.size(); i++)
	{
		if(std::find(s.begin(), s.end(), keylog[i][2]) == s.end())
			s.push_back(keylog[i][2]);
		
	}
	print(s);
}	









	/*
	for(int j = 0; j<3; j++)
		for(int i = 0; i<keylog.size(); i++)
		{
			if(j == 0)
				if(std::find(first.begin(), first.end(), keylog[i][0]) == first.end())
				{
					first.push_back(keylog[i][0]);
				}
			if(j == 1)
				if(std::find(first.begin(), first.end(), keylog[i][1] == first.end())
				&& std::find(second.begin(), second.end(), keylog[i][1] == second.end()))
				{
					second.push_back(keylog[i][1]);
				}
		}	
	}
	for(int i = 0; i<keylog.size(); i++)
	{
		for(int j = 0; j<3; j++)
		{
			
		}
	}
	
	return 0;
}*/

