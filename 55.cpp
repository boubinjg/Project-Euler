#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool isPalindrome(unsigned long long i)
{
	std::string str = std::to_string(i);
	for(int i = 0; i<str.length()/2; i++)
	{
		if(str[i] != str[str.length()-i-1])
			return false;
	}
	//std::cout<<str<<std::endl;
	return true;
}
unsigned long long reverse(unsigned long long i)
{
	std::string str = std::to_string(i);
	std::string rev;
	for (std::string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
    		rev += *rit;
	return stol(rev);
}
bool lychrel(unsigned long long num)
{
	for(int i = 0; i<30; i++)
	{
		num+=reverse(num);
		if(isPalindrome(num))
			return true;
	}	
	return false;
}
int main()
{
	int count = 0;
	for(unsigned long long i = 0; i<10000; i++)
	{
		if(!lychrel(i))
			count++;
	}
	std::cout<<count<<std::endl;
	
}

