#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
bool isPerm(std::string longOne, std::string longTwo)
{
	if(longOne.length() != longTwo.length())
		return false;
	else
	{
		for(int i = 0; i<longOne.length(); i++)
		{
			for(int j = 0; j<longOne.length(); j++)
			{
				if(longOne[i] == longTwo[j])
				{
					//std::cout<<"replace"<<std::endl;
					longOne.replace(i,1,"X");
					longTwo.replace(j,1,"X");
					//std::cout<<longOne<<" "<<longTwo<<std::endl;
				}
			}
		}
		for(int i = 0; i<longOne.length(); i++)
		{
			if(longOne.at(i) != 'X' || longTwo.at(i) != 'X')
				return false;
		}
		return true;
	}
}
int main()
{
	int permCount, currentPerm;
	for(int i = 0; i<10000; i++)
	{	
		permCount = 0;
		currentPerm = i;
		for(int j = 0; j<10000; j++)
		{
			std::string longOne = std::to_string((long)pow(j,3)), longTwo = std::to_string((long)pow(i,3));
			if(j!=i && isPerm(longOne, longTwo))
			{
				std::cout<<i<<","<<(long)pow(i,3)<<" "<<j<<","<<(long)pow(j,3)<<std::endl;
				permCount++;
			}	
		}
		if(permCount > 3)
			break;
	}
	std::cout<<currentPerm<<std::endl;
	return 0;
}

