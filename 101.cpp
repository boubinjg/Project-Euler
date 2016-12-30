#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
#include <limits>
#include <set>
#include <fstream>
#include <sstream>
int main()
{
	int count = 0;
	for(int i = 1; i<=10; i++)
	{
		long num = 0;
		for(int j = 0; j<=10; j++)
		{
			num += pow(-i,j);	
		}
		std::cout<<i<<" "<<num<<std::endl;
	}
	return 0;
}

