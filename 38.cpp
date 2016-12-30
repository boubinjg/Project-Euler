#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
std::string gen(int num)
{
	std::string s = "";
	for(int i = 1; s.size()<9; i++)
	{
		s+= std::to_string(i*num);
	}
	return s;
}
std::string check(int mult)
{
	std::string mul = gen(mult);
	std::vector<char> c(0);
	if(mul.length()==9)
	 for(int k = 0; k<9; k++)
	 {
		
		if( std::find(c.begin(), c.end(),mul.at(k)) == c.end() && mul.at(k)!='0')
		{
			c.push_back(mul.at(k));	
		}
	 }	
	if(c.size() == 9)
	{	
		return mul;
	}
	return "0";
}
int main()
{
	std::string highest = "";
	for(int i = 0; i<10000; i++)
	{
		if(check(i)>highest)
			highest = check(i);
	}
	std::cout<<highest<<std::endl;
	return 0;
}

