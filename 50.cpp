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
	std::vector<int> v = SOE(1000000);
	
	int count = 0, highCount = 0, highNum = 0, num = 0;
	for(int i = 1; i<v.size(); i++)
	{
		std::cout<<i<<" ";
		for(int j = i-1; j>0; j--)
		{
			num = 0;
			count = 0;
			for(int k = j; k>0; k--)
			{
				num+=v[k];
				count++;
				if(num == v[i] && highCount<count)
				{
					highNum = num;
					highCount = count;
				}
				if(num>v[i])
					break;
			}
		}
		std::cout<<highCount<<" "<<highNum<<std::endl;
	}
	
	return 0;
}

