#include <iostream>
#include <math.h>
int primes [500500];
int init [500500];
int getFactorSum(int num)
{	
	int ret = 0;
	
	for(int j = 1; j<num; j++)
	{
		if(num%j==0)
			ret+=j;
	}
	return ret;
}
int main()
{
	
	std::cout<<sum<<std::endl;
	return 0;
}
