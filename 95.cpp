#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
#include <limits.h>
std::vector<int> fs(2000001);
int limit = 1000000;
void factorSeive()
{
	for(int i = 1; i<= limit; i++)
	{	
		for(int j = 2*i; j<=2*limit; j+=i)
			fs[j] += i;	 
	}
}
void print(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<std::endl;
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> longest, v;
	std::vector<bool> num(1000000);
	int n = 0, maxsize = 0, res = 0;
	bool found = false;
	factorSeive();
	for(int x = 4; x<=limit; x++)
	{
		if(num[x]) 
			continue;
		v.clear();
		n = x;
		found = false;
		while(std::find(v.begin(), v.end(),n) == v.end())
		{
			v.push_back(n);
			n = fs[n];
			if(n > limit || num[n])
			{
				found = true;
				break;
			}
		} 
		if(!found)
		{
			int min = INT_MAX;
			int first = std::find(v.begin(), v.end(), n) - v.begin();
			if(v.size() - first > maxsize)
			{
				for(int i = first; i<v.size(); i++)
					if(v[i] < min)
						min = v[i];
				maxsize = v.size() - first;
				res = min;
			}
			
		}
		for(int i = 0; i<v.size(); i++)
			num[v[i]] = true;
	}
	std::cout<<res<<std::endl;
}

