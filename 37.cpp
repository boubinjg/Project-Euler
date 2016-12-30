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
	if(num == 1 || num == 0)
		return false;
	return true;
}
int check(std::string s)
{
	std::string s1 = s;
	std::string s2 = s;
	if(!isPrime(std::stoi(s)))
		return 0;
	for(int i = 0; i<s.length()-1; i++)
	{
		s1 = s1.substr(0,s1.length()-1);
                s2 = s2.substr(1,s2.length());

		if(!(isPrime(std::stoi(s1))&&isPrime(std::stoi(s2))))	
			return 0;
		
		//std::cout<<s1<<" "<<s2<<std::endl;
	}
	std::cout<<s<<std::endl;
	return stoi(s);
}
int main()
{	
	int count = 0;
	//count+=check("3797");
	for(int i = 10; i<750000; i++)
	{	
		//std::cout<<i<<" "<<count<<std::endl;
		count+=check(std::to_string(i));
	}
	std::cout<<count<<std::endl;
	return 0;
}

