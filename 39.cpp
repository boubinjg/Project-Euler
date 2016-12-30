#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
int main()
{
	int count = 0, highNum = 0, highCount = 0;
	for(int i = 1; i<=1000; i++)
	{
		for(int a = 1; a<i; a++)
		{
			for(int b = 1; b<a; b++)
			{
				if(a*a + b*b == (i-a-b)*(i-a-b))
				{
					count++;
					if(count>highCount)
					{
						highNum = i;
						highCount = count;
					}
					std::cout<<a<<" "<<b<<" "<<(i-a-b)<<std::endl;		
				}
			}
		}
		std::cout<<std::endl;
		count = 0;
	}
	std::cout<<highNum<<std::endl;
	return 0;
}

