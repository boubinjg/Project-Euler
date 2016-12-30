#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
int totient(int n)
{

    float result = n;   // Initialize result as n
 
    // Consider all prime factors of n and for every prime
    // factor p, multiply result with (1 - 1/p)
    for (int p=2; p*p<=n; ++p)
    {
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (float) p));
        }
    }
 
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result *= (1.0 - (1.0 / (float) n));
 
    return (int)result;
}
int main()
{
	double max = 0, maxNum=0, cur = 0;
	for(int i = 1; i<1000000; i++)
	{
		cur = totient(i);
		if(i/cur > max)
		{
			max = i/cur;
			maxNum = i;
		}
	}
	std::cout<<max<<" "<<maxNum<<std::endl;
	return 0;
}

