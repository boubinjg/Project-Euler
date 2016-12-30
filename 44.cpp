#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
int getPenta(int n)
{
        return (n*(3*n-1)/2);
}

bool isPenta(int num)
{
	for(int i = 1; i<num; i++)
	{	
		if(getPenta(i) == num)
			return true;
		if(getPenta(i)>num)
			return false;
	}
	
	return false;
}
int main()
{
	int count = 0;
	/*for(int i = 1; i<10; i++)
	{
		std::cout<<getPenta(i)<<std::endl;
	}*/
	for(int i = 1; i<10000; i++)
	{	
		for(int j = 1; j<i; j++)
		{
			if(isPenta(getPenta(i)+getPenta(j)) &&isPenta(getPenta(i)-getPenta(j)))
			{	
				count = getPenta(i)-getPenta(j);
				break;
			}
	
		}
		if(count>0)
			break;
		std::cout<<i<<std::endl;
	}
	std::cout<<count<<std::endl;
	return 0;
}

