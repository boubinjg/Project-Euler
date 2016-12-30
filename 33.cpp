#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
int main()
{
	int totalNum = 1, totalDenom = 1;
	for(double i = 1; i<100; i++)
	{
		for(int j = 1; j<i; j++)
		{
			//std::cout<<i<<" "<<j<<std::endl;
			if(j/i < 1.0)
			{	
				if(j%10 == ((int)i)/10)
				{
					double num = j/10;
					double denom = (double)((int)i%10);
					if(denom != 0 && j/i == num/denom)
					{	
						std::cout<<j<<"/"<<i<<std::endl;
						totalNum*=j;
						totalDenom*=i;
					}
				}
			}
		}
	}
	std::cout<<totalNum<<" "<<totalDenom<<std::endl;
	return 0;
}

