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
int main()
{
	for(int i = 100000; true; i++)
	{
		if(isPerm(std::to_string(i), std::to_string(i*2)) && 
		   isPerm(std::to_string(i), std::to_string(i*3)) &&
		   isPerm(std::to_string(i), std::to_string(i*4)) &&
		   isPerm(std::to_string(i), std::to_string(i*5)) &&
		   isPerm(std::to_string(i), std::to_string(i*6)) 
		   )
		{	
			std::cout<<i<<std::endl;
			break;
		}
		
	}
	return 0;
}

