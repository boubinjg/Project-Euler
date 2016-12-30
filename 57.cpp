#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include <sstream>
#include <iomanip>
int main()
{
	std::string num = "3", denom = "2", sto = "";
	int count = 0;
	for(int i = 1; i<=1000; i++)
	{
		num = bigInt::addInt(num,denom);
		
		//swap
		sto = num;
		num = denom;
		denom = sto;

		num = bigInt::addInt(num,denom);
		if(num.length() > denom.length())
			count++;
		std::cout<<num<<"/"<<denom<<std::endl;
	}
	std::cout<<count<<std::endl;
	return 0;
}

