#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include <sstream>
#include <iomanip>
std::vector<int> v;
void calcNumValue(std::string num)
{
	int sum = 0;
	for(int i = 0; i<num.length(); i++)
	{
		sum += num.at(i) - '0';
	}
	std::cout<<sum<<std::endl;
}
void calcFrac(long length, std::string num, std::string denom)
{
	if(length == 0)
		calcNumValue(num);
	else
	{
		std::string sto = denom;
		denom = num;
		num = sto;
		num = bigInt::addInt(num,bigInt::multInt(denom,v[length-1]));
		length--;
		calcFrac(length, num, denom);
	}
}
int main()
{
	v.push_back(2);
	long mul = 1;
	//std::cout<<v[0];
	for(int i = 0; i<99; i++)
	{
		if(i%3 == 1)
		{
			v.push_back(mul*2);
			mul++;
		}
		else
			v.push_back(1);
		//std::cout<<v[i+1];
	}
	calcFrac(v.size()-1,"1", std::to_string(v[v.size()-1]));
	return 0;
}
