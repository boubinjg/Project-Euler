#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool choose(int n, int r)
{
	int nmr = n-r;
	double count = 1;
	for(int i = n; i>0; i--)
	{
		count*=i;
		if(r>0)
			count/=r;
		if(nmr>0)
			count/=nmr;
		r--;
		nmr--;
		
		if(count>=1000000)
			return true;
	}
	return false;
}
int main()
{
	int count = 0;
	for(int i = 0; i<=100;i++)
	{
		for(int j = 1; j<i; j++)
		{
			if(choose(i,j))	
				count++;
		}
	}
	std::cout<<count<<std::endl;
	return 0;
}

