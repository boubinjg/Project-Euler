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
	int sum = 0;
	double min = 0, minNum = 0, minDenom = 0, number = 3.0/7.0;
	for(double num = 1; num<=1000000; num++)
	{
		for(double denom = num+1; denom<=1000000; denom++)
		{	
			if(num/denom < min)
				break;
			else if( (num/denom) < number && Euler::GCD(num,denom)==1)
			{
				min = num/denom;
				minNum = num;
				minDenom = denom;
				break;
			}
		}
		if((int)num%10000 == 0)
			std::cout<<num<<std::endl;
	}
	std::cout<<minNum<<" "<<minDenom<<std::endl;
	return 0;
}

