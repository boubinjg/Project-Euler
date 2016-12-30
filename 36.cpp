#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool isPalindrome(std::string s)
{
	for(int i = 0; i<s.length()/2; i++)
		if(s.at(i) != s.at(s.length()-i-1))
			return false;
	return true;
}
std::string toBinary(int num)
{
	std::string s = "";
	int tpow = 0;
	for(int j = 0; j<20; j++)
	{
		if(num>=pow(2,j))
			tpow++;
	}
	for(int i = tpow-1; i>=0; i--)
	{
		if(num>=(int)pow(2,i))
		{	
			s+="1";
			num-=pow(2,i);
			//std::cout<<i<<std::endl;
		}
		else
			s+="0";
	}
	return s;
}
int main()
{
	int sum = 0;
	for(int i = 1; i<1000000; i++)
	{
		if(isPalindrome(toBinary(i)) && isPalindrome(std::to_string(i)))
		{	
			std::cout<<i<<" "<<toBinary(i)<<std::endl;
			sum+=i;
		}
	}

	std::cout<<sum<<std::endl;
	return 0;
}

