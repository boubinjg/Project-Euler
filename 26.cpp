#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
int ret;
bool primitiveRoot(int prime)
{
	//see if a specific prime has 10 as a primitive root
	std::vector<int> v = {1,3,7,9};
	ret = 0;
	for(int i = 0; i<100; i++)
	{
		if(std::find(v.begin(), v.end(), prime%10)!= v.end())
		{
			v.erase(std::remove(v.begin(),v.end(),prime%10),v.end());
			if(v.empty()&&ret == 0)	
				ret = i;
				
				
		}
		prime*=prime;
	}
	if(v.empty())
		return true;
	else
		return false;
}
bool isprime(int num)
{
	for(int i = 2; i<num; i++)
	{	
		if(num%i==0)
			return false;
	}
	return true;
}
int main()
{
	for(int i = 999; i>0; i--)
	{
		if(primitiveRoot(i) && isprime(i))
		{
			std::cout<<i<<" "<<ret<<std::endl;
		}
	}
}

