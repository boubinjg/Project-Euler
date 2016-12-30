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
	int num = 0, minNum = 0;
	double min = 100;
	for(int i = 2; i<10000000; i++)
	{	
		num = Euler::totient(i);
		if((float)i/(float)num < min && Euler::isPerm(std::to_string(i),std::to_string(num)))
		{
			min = float(i)/(float)num;
			minNum = i;
		}
	}
	std::cout<<minNum<<" "<<min<<" "<<Euler::totient(minNum)<<std::endl;
	return 0;
}

