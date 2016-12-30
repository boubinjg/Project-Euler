#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool getPrime(int num)
{
	for(int i = 2; i<num; i++)
		if(num%i==0)
			return false;
	return true;
}
void getPrimeVect() 
{
	std::vector<int> ret;
	int num = 2;
	while(ret.size()!=7)
	{
		if(getPrime(num))
		{
			std::cout<<num<<std::endl;
			ret.push_back(num);
		}
		num++;
	}
	for(auto i = ret.begin(); i!=ret.end(); i++)
        {
                std::cout<< *i << " ";
        }
	
}
int main()
{
	getPrimeVector();
	return 0;
}

