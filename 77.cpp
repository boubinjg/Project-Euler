#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
bool isprime(int n)
{
	if(n<2)
		return false;
	for(int i = 2; i<=n/2; i++)
		if(n%i == 0)
			return false;
	return true;
}
void print(std::vector<int> p)
{
	for(int i = 0; i<p.size(); i++)
	{
		std::cout<<p[i]<<" ";
	}
	std::cout<<std::endl;
}
int main()
{
  int count = 0;
  for(int num = 1; num<100; num++)
  {
	std::vector<std::vector<int> > partition;
	std::vector<int> p(num);
        count = 0;
	p[0] = num;
	int k = 0;
	while(true)
	{
		partition.push_back(p);
		int rem = 0;
		while(k>=0 && p[k] == 1)
		{
			rem += p[k];
			k--;
		}	
		if(k < 0)
			break;

		p[k]--;
		rem++;
		while(rem > p[k])
		{
			p[k+1] = p[k];
			rem = rem - p[k];
			k++;
		}
		p[k+1] = rem;
		k++;
	}
	for(int i = 0; i<partition.size(); i++)
	{
		int itcount = 0;
		for(int j = 0; j<partition[i].size() && partition[i][j]>0; j++)
		{
			
			if(!isprime(partition[i][j]) || partition[i][j] == 1)
			{
				break;	
			}
			itcount += partition[i][j];
			if(itcount == num)
			{
				count++;
				//std::cout<<partition[i][j]<<std::endl;
				//print(partition[i]);
			}
		}
	}
  	std::cout<<num<<" "<<count<<std::endl;
	if(count > 5000)
		break;
  }
}
