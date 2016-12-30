#include <iostream>
#include <math.h>
int primes [500500];
int init [500500];
void getPrime()
{	
	int count = 0;
	long ret = 0;
	int lastPrime = 0;
	for(int i = 2; lastPrime < 2000000; i++)
		for(int j = 2; j<=i; j++)
		{
			if(i == 2)
			{
				ret += i;
				count++;
			}
			if(i%j==0 && i!= 2)
				break;
			else if(i == j+1)	
			{	
				ret += i;
				lastPrime = i;
				//std::cout<<lastPrime<<std::endl;
			}
		}
	std::cout<<ret<<std::endl;
}
int main()
{
	//get prime must provide 500500 for the actual solution
	getPrime();
	//largestFactor(num);
	return 0;
}
