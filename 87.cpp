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
	int ubound = 50000000, count = 0;
	int bound = (int)(std::sqrt(ubound));
	std::vector<int> soe = soe::seive(bound);
	std::cout<<soe[0]<<std::endl;
	std::vector<bool> nums(ubound);
	for(int i = 0; i<soe.size(); i++)
	 for(int j = 0; j<soe.size() && pow(soe[j],3)< ubound; j++)
	  for(int k = 0; k<soe.size() && pow(soe[k],4) <ubound; k++)
	  {
	   int p = pow(soe[i],2) + pow(soe[j],3) + pow(soe[k],4);
	   if(p<ubound)
	   {
		if(nums[p] == 0)
		{
		 nums[p] = 1;	  
		 count++;
	        }  
           }
	  }
	std::cout<<count<<std::endl;
	return 0;
}

