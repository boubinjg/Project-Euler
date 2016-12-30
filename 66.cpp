#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
std::string num = "0", denom = "0", sto = "0";
void factor()
{
	for(int i = 2; i<=denom; i++)
	{
		if(num%i==0 && denom%i==0)
		{
			num/=i;
			denom/=i;
			i--;
		}
	}
}
int main()
{
	int x = 2;
	for(int i = 0; i<10; i++)
	{
		num = std::to_string(x-1), denom = "2", sto = "0";
		for(int j = 0; j<i; j++)
		{
			bigInt::addInt(num,bigInt::addInt(num,bigInt::multInt(denom,2)));
			//num += 2*denom;
			sto = num;
			num = denom;
			denom = sto;
			//num*=(x-1);
		}
		//num += denom;
		//factor();
		std::cout<<num<<" "<<denom<<std::endl;
	}
}

