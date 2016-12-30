#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool isPerm(std::string s1, std::string s2)
{
	std::sort(s1.begin(),s1.end());
	std::sort(s2.begin(),s2.end());
	if(s1!=s2)
		return false;
	return true;
}
bool isPrime(int num)
{
	for(int i = 2; i<=num/2; i++)
		if(num%i==0)
			return false;
	return true;
}
int main()
{
	for(int i = 1000; i<10000; i++)
	{
		for(int j = 1000; j<4500&&j+i<10000; j++)
		{
			if(isPrime(i) && isPrime(i+j) && isPerm(std::to_string(i),std::to_string(i+j)))
			{	
				//std::cout<<i<<" "<<j<<std::endl;
				if(isPrime(i+j+j)&&isPerm(std::to_string(i),std::to_string(i+j+j)))
				{	
					std::cout<<i<<" "<<i+j<<" "<<i+j+j<<" "<<j<<std::endl;
				}
			}
		}
	}
	return 0;
}

