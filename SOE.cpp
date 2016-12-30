#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
std::vector<int> SOE(int n)
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
int main()
{
	//bool p[10001];
	std::vector<int> v = SOE(1000000);
	for(int i = 0; i<v.size(); i++)
                std::cout<<v[i]<<std::endl;
	return 0;
}

