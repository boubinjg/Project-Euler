#include <iostream>
#include <math.h>
int abundant [6965];
int getFactorSum(int num)
{	
	int ret = 0;
	
	for(int j = 1; j<num; j++)
	{
		if(num%j==0)
			ret+=j;
	}
	return ret;
}
int main()
{
	for(int i = 0; i<6965; i++)
		abundant[i] = 0;
	int abund = 0;
	for(int i = 0; i<28123; i++)
	{
		if(getFactorSum(i)>i)
		{
			abundant[abund] = i;
			abund++;
		}	
	}
	std::cout<<abund<<std::endl;
	
	bool abd = false;
	int sum = 0;
	for(int j = 0; j<28123; j++)
	{		
		abd = false;
		for(int k = 0; k<6965; k++)
		{
			for(int l = 0; l<6965; l++)
			{
				if(abundant[l]+abundant[k] == j)
				{	
					abd = true;
					break;
				}
				else if(abundant[l]+abundant[k]>j)
					break;
			}
			if(abd)
				break;

		}
		if(!abd)
		{
			sum+=j;
			std::cout<<j<<std::endl;
		}
	}
	std::cout<<sum;
	return 0;
}
