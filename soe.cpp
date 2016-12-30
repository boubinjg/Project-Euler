#include "bigInt.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "soe.h"
#include <bits/stdc++.h>
std::vector<int> soe::seive(int n)
{
	// Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        bool prime[n+1];
        std::memset(prime, true, sizeof(prime));

        for (int p=2; p*p<=n; p++)
        {
                // If prime[p] is not changed, then it is a prime
                if (prime[p] == true)
                {
                // Update all multiples of p
                for (int i=p*2; i<=n; i += p)
                        prime[i] = false;
                }
        }

        //operations
        std::vector<int> v;
        for (int p=2; p<=n; p++)
                if (prime[p])
                        v.push_back(p);

        return v;
}
std::vector<bool> soe::boolseive(int n)
{
	bool prime[n+1];
        std::memset(prime, true, sizeof(prime));

        for (int p=2; p*p<=n; p++)
        {
                // If prime[p] is not changed, then it is a prime
                if (prime[p] == true)
                {
                // Update all multiples of p
                for (int i=p*2; i<=n; i += p)
                        prime[i] = false;
                }
        }

        //operations
        std::vector<bool> v;
	v.push_back(false);
	v.push_back(false);
        for (int p=2; p<=n; p++)
        	v.push_back(prime[p]);

        return v;

}


