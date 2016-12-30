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
#include <climits>
std::vector<std::string> v;
std::vector<std::vector<std::string> > perms;
std::vector<int> nums;
std::vector<std::vector<int> > numHolder;
std::vector<int> results;
int findPerm(int index)
{
	std::string str = v[index];
	std::sort(str.begin(), str.end());
	std::string cmp;
	for(int i = 0; i<v.size(); i++)
	{
		if(i != index)
		{
			cmp = v[i];
			std::sort(cmp.begin(), cmp.end());
			if(cmp == str)
			{
				std::vector<std::string> sp;
				sp.push_back(v[index]);
				sp.push_back(v[i]);
				perms.push_back(sp);
			}
		}
	}
}
void print(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
}
void permgen(int n)
{
	for(long i = 0; i*i<pow(10,n); i++)
	{
		if(i*i > pow(10,n-1))
		{
			nums.push_back(i*i);
		}
	}
}
int remap(int num, std::vector<int> perm)
{
	int res = 0;
	for(int i = perm.size()-1; i>=0; i--)
	{
		int digit = (num/(int)pow(10,i)) % 10;
		res += digit * (int)pow(10,perm.size() - perm[perm.size()-i-1]-1);
	}
	return res;
}
void highestSquare(std::string a, std::string b)
{
	std::vector<int> perm;
	for(int i = 0; i<a.size(); i++)
	{
		char cur = a.at(i);
		for(int j = 0; j<a.size(); j++)
		{
			if(cur == b.at(j))
			{
				perm.push_back(j);
			}
		}
	}	
	for(int i = 0; i<nums.size(); i++)
	{
		int other = remap(nums[i], perm);
		if(std::find(nums.begin(), nums.end(), other) != nums.end())
		{	
			results.push_back(other);
		}
	}
}
int main()
{
	int count = 0;
	
	std::ifstream infile("98.txt");
	
	while(infile)
	{
		std::string s;
		if(!getline(infile, s)) 
			break;
		std::istringstream ss(s);
		while(ss)
		{
			std::string s;
			if(!getline(ss,s,',')) 
				break;
			s = s.substr(1,s.size()-2);
			v.push_back(s);
		}
		
	}
	for(int i = 0; i<v.size(); i++)
		findPerm(i);
	int max = 0;
	int min = INT_MAX;
	for(int i = 0; i<perms.size(); i++)
	{
		if(perms[i][0].length() > max)
			max = perms[i][0].length();
		if(perms[i][0].length() < min)
			min = perms[i][0].length();
	}
	
	int hs = 0;
	for(int f = 2; f<=9; f++)
	{
		nums.clear();
		permgen(f);

		for(int j = 0; j<perms.size(); j++)
		{
			if(perms[j][0].length() == f)
				highestSquare(perms[j][0], perms[j][1]);
		}
	
		std::sort(results.begin(), results.end());
		//find highest
		for(int i = 0; i<results.size(); i++)
		{
			bool dupe = false;
			std::string resultString = std::to_string(results[i]);
			std::sort(resultString.begin(), resultString.end());
			for(int j = 0; j<resultString.size()-1; j++)
			{
				if(resultString[j] == resultString[j+1])
					dupe = true;
			}
			if(!dupe)
				max = results[i];
		}
		results.clear();
	}
	std::cout<<max<<std::endl;
	return 0;
}

