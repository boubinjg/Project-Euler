#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
int factorial(int n)
{
	int ret = 1;
	for(int i = 1; i<=n; i++)
	{
		ret *= i; 
	}
	return ret;
}
int main()
{
	std::vector<int> table(10000000);
	std::vector<int> sto;
	table[871] = 2;
	table[872] = 2;
	table[169] = 3;
	table[363601] = 3;
	table[1454] = 3;
	table[45361] = 2;
	table[45362] = 2;
	table[1] = 1;
	table[2] = 1;
	table[145] = 1;
	table[40585] = 1;
	int max = 0;
	int maxNum = 0;
	int count = 0;
	for(int i = 3; i<1000000; i++)
	{
		//int i = 3569;
		int temp = 0;
		std::string s = std::to_string(i);
		bool found = false;
		sto.clear();
		for(int j = 1; !found; j++)
		{
			for(int k = 0; k<s.length(); k++)
				temp += factorial(s[k] - '0'); 
			s = std::to_string(temp);
			if(std::stoi(s) == i)
				table[temp] = 1;
			temp = 0;
			if(table[std::stoi(s)] != 0)
			{
				found = true;	
				table[i] = sto.size()+1+table[std::stoi(s)];
				sto.clear();
			}
			else
				sto.push_back(std::stoi(s));
		}
		
		if(table[i] > max)
		{
			max = table[i];
			maxNum = i;
		}
		if(table[i] == 60)
			count++;
	
	}
	std::cout<<maxNum<<": "<<max<<std::endl;
	std::cout<<count<<std::endl;
	return 0;
}

