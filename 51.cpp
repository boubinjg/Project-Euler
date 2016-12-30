#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#include <sstream>
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
int perm(int num, int rep, std::string p)
{
	std::string n = std::to_string(num);
	for(int i = 0; i<p.length(); i++)
	{
		if(p[i] == '1')
		{	
			n[i] = (char)(rep+'0');	
		}
	}
	return stoi(n);
}
int main()
{
	//bool p[10001];
	std::vector<int> v = SOE(1000000);
	std::stringstream ss;
	
	
	
	for(int x = 0; x<v.size(); x++)
	{
	       //std::cout<<v[x]<<std::endl;
	       if(v[x]>100000)
		for(int i = 0; i<=1; i++)
	 	 for(int j = 0; j<=1; j++)
	  	  for(int k = 0; k<=1; k++)
           	   for(int l = 0; l<=1; l++)
	    	    for(int m = 0; m<=1; m++)
	     	     for(int n = 0; n<=1; n++)
		     {
			std::string s;
			std::ostringstream convert;
			convert << i<<j<<k<<l<<m<<n;
			s = convert.str();
			int count = 0;
			int sprime = 1000000;
			for(int a = 0; a<10; a++)
			{
				int num = perm(v[x],a,s);
				//std::cout<<count<<std::endl;
				if(std::find(v.begin(),v.end(),num)!=v.end())
				{	
					if(sprime>num)
						sprime=num;
					count++; 
				}
			}
			if(count == 8)
			{
				std::cout<<sprime<<std::endl;
				break;
			}
	     	     }
	}
	return 0;
}

