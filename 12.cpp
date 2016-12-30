#include <iostream>
#include <math.h>
int primes [500500];
int getFactors(int num)
{	
	int count = 0;
	
	for(int j = 1; j<=num/2+1; j++ )
	{
		if(num%j==0)
			count++;
	}
	return count;
}
int main()
{
	int factors = 0;
	int i = 1, num = 0;
	while(factors < 500)
	{
		num += i;
		i++;
		factors = getFactors(num);
		if(factors>100)
			std::cout<<factors<<" "<<num<<std::endl;
	}
	return 0;
}
