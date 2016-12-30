#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
int main()
{
	int count = 0;
	for(int i = 200; i>=0; i-=200)	
	 for(int j = i; j>=0; j-=100)
	  for(int k = j; k>=0; k-=50)
	   for(int l = k; l>=0; l-=20)
	    for(int m = l; m>=0; m-=10)
	     for(int n = m; n>=0; n-=5)
	      for(int o = n; o>=0; o-=2)
		count++;
	std::cout << count<<std::endl;
	return 0;
}

