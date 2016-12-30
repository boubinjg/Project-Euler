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
void largestFactor(double num)
{
	double check;
	int lfactor = 0;
	for(int i = 0; i<10000; i++)
	{
		check = num/primes[i]; 
		if(check == (int) check)
			lfactor = primes[i];
	}
	std::cout << lfactor << std::endl;
}
int main()
{
	//get prime must provide 500500 for the actual solution
	getPrime(10000);
	double num = 600851475143;
	largestFactor(num);
	return 0;
}
