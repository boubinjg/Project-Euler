#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"

int main()
{
	std::string s = "";
	int sum = 0, maxSum = 0;
	for(int i = 1; i<=100; i++)
	{
		for(int x = 0; x<100; x++)
		{
			s ="1";
			sum = 0;
			for(int j = 0; j<x; j++)
			{
				s = bigInt::multInt(s,i);
			}
			for(int k = 0; k<s.length(); k++)
			{
				sum+=(s.at(k)-'0');
			}
		//	std::cout<<sum<<std::endl;
			if(sum>maxSum)
				maxSum = sum;
		}
	}
	std::cout<<maxSum;
	return 0;
}

