#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

bool isPrime(int num)
{
	for(int i = 2; i<num; i++)
		if(num%i==0)
			return false;
	
	return true;
}
int check(std::string s)
{
	std::string news = "";
	for(int i = 0; i<s.length(); i++)
	{
		news = "";
		//std::cout<<s<<std::endl;
		news +=	s.at(s.length()-1);
		news += s.substr(0,s.length()-1);
		s = news;
		
		if(!isPrime(std::stoi(s)))
		{	
			return 0;
		}
	}
	return 1;
}
int main()
{	
	int count = 0;
	for(int i = 2; i<1000000; i++)
	{
		count+=check(std::to_string(i));
		if(i%100000 == 0)
			std::cout<<i<<std::endl;
	}
	std::cout<<count<<std::endl;
	return 0;
}

