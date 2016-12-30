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
	bool found = false;
	for(int target = 10000; !found; target += 10000)
	{
		std::vector<long> ways(target);
		ways[0] = 1;
		for(int i = 1; i<=target-1; i++)
		{		
			for(int j = i; j<= target; j++)
			{
			ways[j] += ways[j-i];
			if(ways[j] > 1000000)
				ways[j] -= 1000000;
			}
			if(ways[i] == 1000000)	
			{
				std::cout<<i<<std::endl;
				found = true;
				break;	
			}
		}
	}
	return 0;
}

