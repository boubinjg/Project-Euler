#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
int main()
{
	std::string constant = "";
	int ret = 1;
	for(int i = 0; i<1000000; i++)
	{
		constant+=std::to_string(i);
	}
	for(int i = 1; i<=1000000; i*=10)
	{
		std::cout<<i<<std::endl;
		ret *= constant.at(i)-'0';
	}
	std::cout<<ret<<std::endl;
	return 0;
}
