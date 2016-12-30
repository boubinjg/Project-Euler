#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
int main()
{
	int a=0,b=0,c=0, count=0, num=0;
	std::vector<int> triples;
	for(int m = 1; m<1000; m++)
	{
		for(int n = 1; n<m; n++)
		{
			if((m-n)%2 == 1 && Euler::GCD(m,n) == 1)
			{
				a = m*m - n*n;
				b = 2*m*n;
				c = m*m+n*n;
				num = a+b+c;
				for(int k = 1; k*num<=1500000; k++)
				{
					triples.push_back(k*num);
				}
			}
		}
	}
	std::sort(triples.begin(), triples.end());
	std::cout<<triples.size()<<std::endl;
	for(int i = 1; i<triples.size()-1; i++)
	{
		if(triples[i] != triples[i-1] && triples[i] != triples[i+1])
			count++;
	}
	if(triples[0] != triples[1])
		count++;
	if(triples[triples.size()-1] != triples[triples.size()-2])
		count++;
	std::cout<<count<<std::endl;
	return 0;
}

