#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
int main()
{
	long ret = 0, curNum = 0;
	for(long i = 1; i<=1000; i++)
	{
		curNum = i;
		for(long j = 1; j<i; j++)
		{
			curNum*=i;
			curNum%=100000000000;
		}
		//std::cout<<curNum<<std::endl;
		ret+=curNum;
	}
	std::cout<<ret<<std::endl;
	return 0;
}

