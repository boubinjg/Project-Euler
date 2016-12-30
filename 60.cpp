#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
std::vector<bool> bv = soe::boolseive(1000000);
bool isPrime(int n)
{
	if(n<bv.size())
		return bv[n];
	
	for(int i = 3; i<n/2; i+=2)
		if(n%i == 0)
			return false;
	return true;
}
int main()
{
	std::vector<int> v = soe::seive(10000);
	std::vector<bool> bv = soe::boolseive(1000000);
	int num;

	for(int i = 1; v[i]<50; i++)
	 for(int j = i+1; v[j]<6000; j++)
	 {
	  if(isPrime( (stoi( std::to_string(v[i]) + std::to_string(v[j]) ) )) &&
             isPrime( (stoi( std::to_string(v[j]) + std::to_string(v[i]) ) ))) 
	  	for(int k = j+1; v[k]<7500; k++)
		{
			if(isPrime( (stoi( std::to_string(v[i]) + std::to_string(v[k]) ) )) &&
             		   isPrime( (stoi( std::to_string(v[k]) + std::to_string(v[i]) ) )) &&
			   isPrime( (stoi( std::to_string(v[k]) + std::to_string(v[j]) ) )) &&
 			   isPrime( (stoi( std::to_string(v[j]) + std::to_string(v[k]) ) )))
				for(int l = k+1; l<v.size(); l++)
				{
					if(isPrime( (stoi( std::to_string(v[i]) + std::to_string(v[l]) ) )) &&
                           		   isPrime( (stoi( std::to_string(v[l]) + std::to_string(v[i]) ) )) &&
                           		   isPrime( (stoi( std::to_string(v[l]) + std::to_string(v[j]) ) )) &&
                           		   isPrime( (stoi( std::to_string(v[j]) + std::to_string(v[l]) ) )) &&
					   isPrime( (stoi( std::to_string(v[k]) + std::to_string(v[l]) ) )) &&
                           		   isPrime( (stoi( std::to_string(v[l]) + std::to_string(v[k]) ) )))
						for(int m = k+1; m<v.size(); m++)
						{
							if(
					   isPrime( (stoi( std::to_string(v[i]) + std::to_string(v[m]) ) )) &&
                                           isPrime( (stoi( std::to_string(v[m]) + std::to_string(v[i]) ) )) &&
                                           isPrime( (stoi( std::to_string(v[m]) + std::to_string(v[j]) ) )) &&
                                           isPrime( (stoi( std::to_string(v[j]) + std::to_string(v[m]) ) )) &&
                                           isPrime( (stoi( std::to_string(v[k]) + std::to_string(v[m]) ) )) &&
                                           isPrime( (stoi( std::to_string(v[m]) + std::to_string(v[k]) ) )) &&
					   isPrime( (stoi( std::to_string(v[m]) + std::to_string(v[l]) ) )) &&
                                           isPrime( (stoi( std::to_string(v[l]) + std::to_string(v[m]) ) )))
						std::cout<<v[i]+v[j]+v[k]+v[l]+v[m]<<std::endl; 

						}		
				}
		}
		std::cout<<v[i]<<" "<<v[j]<<std::endl;
	 }
	return 0;
}

