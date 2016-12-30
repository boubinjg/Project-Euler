#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
int main()
{
	int count = 0;
	for(int i = 1; i<10; i++)
	{
		int j = 1;
		while((pow(i,j) >= pow(10,j-1)))
		{
			std::cout<<i<<" "<<j<<" "<<pow(i,j)<<std::endl;
			count++;
			j++;
		}
	}
	std::cout<<count<<std::endl;
	return 0;
}

