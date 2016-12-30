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
	std::string n ="0";
	for(int num = 2; num<=1000000; num++)
	{
		n= bigInt::addInt(std::to_string(Euler::totient(num)),n);
		//if(num%10000 == 0)
		//	std::cout<<num<<std::endl;
	}
	std::cout<<n<<std::endl;
	return 0;
}

