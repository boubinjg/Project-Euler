#include <iostream>
#include <string>
#include <vector>
bool isprime(int n)
{
	for(int i = 3; i<n/2; i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int main()
{
	
	double primes = 0, nonprimes = 0;
	int mod = 2;
	int num = 1;
	for(int i = 0; i<25000; i++)
	{
		for(int j = 0; j<4; j++)
		{
			num+=mod;
			if(isprime(num))
				primes++;
			else
				nonprimes++;
		}
		if(primes/nonprimes <= .1)
			break;
		else
			mod+=2;
	}
	std::cout <<mod+1<<std::endl;
	return 0;
}

