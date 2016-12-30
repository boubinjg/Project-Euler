#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool isPrime(int num)
{
	for(int i = 2; i<num/2; i++)
	{
		if(num%i==0)
			return false;
	}
	return true;
}
int main()
{
	int ret = 0;
	for(int i = 1; i<1000000; i+=2)
	{
		if(!isPrime(i))
		{
			int count = 0;
			for(int j = 2; j<i; j++)
			{	
				if(isPrime(j))
					for(int k = 1; k<j; k++)
					{
						if(j+2*k*k == i)
							count++;
						if(j+2*k*k >i)
							break;
					}	
			}
			if(count == 0)
			{
				ret = i;		
				break;
			}
		}
	}
	std::cout<<ret<<std::endl;
	return 0;
}

