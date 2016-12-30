#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
int fact(int i)
{
	int ret = 1;
	for(int j = 1; j<=i; j++)
	{
		ret *= j;
	}
	return ret;
}
int main()
{
	//std::cout<<fact(5)<<std::endl;
	int sum = 0, totalSum = 0;
	for(int i = 3; i<100000; i++)
	{
		sum = 0;
		for(int j = 1; j<=i; j*=10)
		{
			sum +=fact(i/j%10);
		}
		if(sum == i)
			totalSum += i;
	}
	std::cout<<totalSum<<std::endl;
	return 0;
}

