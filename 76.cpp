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
	int count = 0;
	std::vector<int> p(100);
	p[0] = 100;
	int k = 0;
	while(true)
	{
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
		
		count++;
	}
	std::cout<<count<<std::endl;
}
