#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
bool isprime(int a)
{
	for(int i = 2; i< a/2; i++)
		if(a%i == 0)
			return false;
	return true;
}
int main()
{
	int count = 0;
	for(int i = 1; i<=12000; i++)
	{
		std::cout<<i<<std::endl;
		for(int j=2*i + 1; j<i*3 && j<=12000; j++)
		{
			if(Euler::GCD(i,j) == 1)
				count++;
		}
	}
	std::cout<<count<<std::endl;
	return 0;
}

