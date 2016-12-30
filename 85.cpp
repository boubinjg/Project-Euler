#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
int rects(int width, int length)
{
	int count = 0;
	for(int i = 0; i<width; i++)
	 for(int j = 0; j<length; j++)
	  count += (width-i) * (length-j);
	return count;
}
int main()
{
	int cur = 0;
	int closest = 0;
	int area = 0;
	for(int i = 1; i<=100; i++)
	{
		for(int j = i; j<=100; j++)
		{
			cur = rects(i,j); 
			if(cur <2000000 && cur>closest)	
			{
				closest = cur;
				area = i*j;
				std::cout<<cur<<std::endl;
			}
		}
	}
	std::cout<<area<<std::endl;

	return 0;
}

