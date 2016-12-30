#include <iostream>
#include <math.h>
int primes [500500];
int init [500500];
void getPrime(int num)
{	
	int count = 0;
	for(int i = 2; count<num; i++)
		for(int j = 2; j<=i; j++)
		{
			if(i == 2)
			{
				primes[count] = i;
				count++;
			}
			if(i%j==0 && i!= 2)
				break;
			else if(i == j+1)	
			{	
				primes[count] = i;
				count++;
				std::cout<<i<<std::endl;
			}
		}
}
void initialize()
{
	for(int i = 0; i<500500; i++)
		init[i] = 0;
}
void divisors()
{
	int zeroIndex = 0;
	int changeIndex = 0;
	int currentIndex = 0;
	
}
void addUp()
{	
	for(int i = 0; i<20; i++)
	{
		std::cout<<primes[i]<<"^"<<init[i]<<std::endl;
	}
}
int main()
{
	//get prime must provide 500500 for the actual solution
	getPrime(1000);
	initialize();
	divisors();
	addUp();
	return 0;
}
