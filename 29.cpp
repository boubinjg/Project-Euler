#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
int number[302];
int order()
{
	int currentNum = 0;
        for(int k = 0; k<301; k++)
        {
                currentNum = number[k];
                number[k] = currentNum%10;
                number[k+1] += currentNum/10;
                //std::cout<<number[k]<<std::endl;
        }
}
void clear()
{
	for(int i = 0; i<302; i++)
	{
		number[i] = 0;
	}
}
std::string power(int a, int b)
{
	clear();
	number[0] = 1;
	for(int i = 1; i<=b; i++)
	{
		for(int j = 0; j<302; j++)
		{	
			number[j]*= a;
		}
		order();
	}
	std::string ret = "";
	for(int k = 0; k<302; k++)
		ret += std::to_string(number[k]);
	return ret;
}
int main()
{
	std::vector<std::string> v;
	//v.push_back(0);
	std::string s [302];
	for(int x = 0; x<302; x++)
	{
		number[x] = 0;
	}
	
	number[0] = 1;
	for(int i = 2; i<=100; i++)
	{
		for(int j = 2; j<=100; j++)
		{
		
			std::string s = power(i,j);
			if(i==2 && j == 4 || i ==4 && j == 2)
				std::cout<<s<<std::endl;
			if(std::find(v.begin(), v.end(), s) == v.end()) {
   	 			v.push_back(s);
			} 
		}
	}
	std::cout<<v.size() <<std::endl;
	
	return 0;
}

