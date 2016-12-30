#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool isPrime(int num)
{
	for(int i = 2; i<=num/2; i++)
	{
		if(num%i==0)
			return false;	
	}
	return true;
}
std::string check(int mult)
{
	
	if(!isPrime(mult))
		return "0";
	std::string mul = std::to_string(mult);
	std::vector<char> c(0);
	 for(int k = 0; k<mul.length(); k++)
	 {
		
		if( std::find(c.begin(), c.end(),mul.at(k)) == c.end() && mul.at(k)!='0' && 
		mul.at(k)-'0'<=mul.length())
		{
			c.push_back(mul.at(k));	
		}
	 }	
	if(c.size() == mul.length())
	{	
		return mul;
	}
	return "0";
}
int main()
{
	std::string highest = "";
	for(int i = 1; i<7654321; i+=2)
	{
		std::cout<<i<<std::endl;
		if(check(i).length()>1)
		{	
			std::cout<<check(i)<<std::endl;
			highest = check(i);
		}
	}
	std::cout<<highest<<std::endl;
	return 0;
}

