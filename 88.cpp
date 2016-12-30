#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
#include <sstream>
#include <set>
std::vector<bool> sieve = soe::boolseive(1000000);
std::vector<int> primes = soe::seive(1000000);
std::vector<std::vector<int> > factors;
void print(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
}
void stov(std::string s)
{
	std::vector<int> v;
	std::stringstream ss(s);
	int i;
	while(ss >> i)
	{
		v.push_back(i);
	}
	factors.push_back(v);
}
void facts(int n, int pn, std::string parentFactors)
{
	int newVal = pn;
	for(int i = n/2; i>= 2; i--)
	{
		if(n%i == 0)
		{
			if(newVal > i)
				newVal = i;
			if(n/i <= pn && i<=pn && n/i <= i)
			{
				stov(parentFactors+std::to_string(i)+" "+std::to_string(n/i));
				newVal = n/i;
			}		
			if(i<=pn)
			{
				facts(n/i,newVal,parentFactors + std::to_string(i) + " ");
			}
		}
	}
} 
bool check(int k, int number)
{
	int m = 1, a = 0;
	facts(number,number,"");
	for(int i = 0; i<factors.size(); i++)
	{
		for(int j = 0; j<factors[i].size(); j++)
		{
			a += factors[i][j];
			m *= factors[i][j];	
		}
		a += k-factors[i].size();
		if(a == m && m == number)
		{
			return true;
		}
		else
		{
			m = 1;
			a = 0;
		}
	}
	return false;
}
int main()
{
	std::vector<int> v;
	int k = 2, count = 0;
	for(int i = 2; k<=12000; i++)
	{
		//std::cout<<i<<" "<<k<<std::endl;
		if(!sieve[i])
		{
			factors.clear();
			if(check(k, i))
			{
				k++;
				v.push_back(i);
				i=k;
				if(k%100 == 0)
					std::cout<<k<<std::endl;
			}
		
		}
	}
	
	std::sort(v.begin(), v.end());
	std::set<int> s(v.begin(), v.end());
	v.assign(s.begin(), s.end());
	std::cout<<v.size()<<std::endl;
	
	for(int i = 0; i<v.size(); i++)
	{
		count += v[i];
	}
	
	std::cout<<count<<std::endl;
}

