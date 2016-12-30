#include <iostream>
#include <string>
#include <vector>
std::string s = "0123456789";
int fact(int num)
{
	int ret = 1;
	for(int i = 1; i<=num; i++)
	{
		ret *= i;
	}
	return ret;
}
int main()
{
	//first one is s, so operation is performed 1000000-1 times.
	int mil = 999999;
	for(int i = 9 ; i>=0; i--)
	{
		std::cout<< s.at(mil/fact(i));
		s.erase(s.begin()+mil/fact(i));
		mil -= (mil/fact(i))*fact(i);
	}
}
