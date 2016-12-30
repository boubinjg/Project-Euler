#include "bigInt.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Euler.h"
int Euler::totient(int n)
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
int Euler::GCD(int m, int n)
{
    int r;

    /* Check For Proper Input */
    if((m == 0) || (n == 0))
        return 0;
    else if((m < 0) || (n < 0))
        return -1;

    do
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    while(true);

    return n;
}
bool Euler::isPerm(std::string s1, std::string s2)
{
        std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	if(s1 == s2)
		return true;
	return false;
}



