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
std::vector<std::vector<int> > nums;
void check()
{
	int maxIndex = 0;
	double max = 0, num = 0;
	for(int i = 0; i<nums.size(); i++)
	{
		num =nums[i][1] * log(nums[i][0]);
		if(num > max)
		{
			max = num;	
			maxIndex = i+1;
		}
	}
	std::cout<<maxIndex<<std::endl;
}
int main()
{
	int count = 0;
	std::ifstream infile("99.txt");
	
	while(infile)
	{
		std::string s;
		if(!getline(infile, s)) 
			break;
		std::istringstream ss(s);
		std::vector<int> v;
		while(ss)
		{
			std::string s;
			if(!getline(ss,s,',')) 
				break;
			v.push_back(std::stoi(s));
		}
		nums.push_back(v);
	}
	check();
	return 0;
}

