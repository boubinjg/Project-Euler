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
				//std::cout<<i<<std::endl;
			}
		}
}
int main()
{
	//get prime must provide 500500 for the actual solution
	getPrime(10001);
	std::cout<<primes[10000]<<std::endl;
	return 0;
}
