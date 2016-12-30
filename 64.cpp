#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
int main()
{
	int total = 0;
	for(int i = 0; i<=10000; i++)
	{	
		int s = i;
        	int m = 0;
        	int d = 1;
        	int a = pow(s,.5);
        	int a0 = a;
  	        int count = 0;
		if(a*a!=s)
		{
			do{
			 m = d*a-m;
			 d = (s-(m*m))/d;
			 a = (a0 + m)/d;
			 count++;
			}while(a != 2*a0);
			if(count%2==1)
				total++;
		}
		std::cout<<i<<" "<<count<<std::endl;
	}
	std::cout<<total<<std::endl;
	return 0;
}

