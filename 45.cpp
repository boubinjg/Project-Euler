#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool isPenta(long num)
{
	for(long i = 1; i<num; i++)
	{	
		if(i*(i*3-1)/2  == num)
			return true;
		if(i*(i*3-1)/2>num)
			return false;
	}
	
	return false;
}
bool isTri(long num)
{
	for(long i = 1; i<num; i++)
	{
		if(i*(i+1)/2 == num)
			return true;
		if(i*(i+1)/2 > num)
			return false;
	}
	return false;
}
int main()
{
	long count = 0;
	long num = 0;
	for(long i = 1; num<1000000000000; i++)
	{	
		num = i*(i*2-1);
		
		std::cout<<i<<" "<<num<<std::endl;
		if(num != 40755 && isPenta(num) && isTri(num))
		{
			count = num;
			break;
		}
	}
	std::cout<<count<<std::endl;
	return 0;
}

