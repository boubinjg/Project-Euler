#include <iostream>
#include <string>
#include <fstream>
int main()
{
	std::string s [100];
	std::ifstream file("13.txt");
    	std::string str; 
	int number [100];
	int i = 0;
    	while (std::getline(file, str))
    	{
		
       		s[i] = str;
		i++;
    	}
	for(int x = 0; x<100; x++)
	{
		number[x] = 0;
	}
	for(int i = 0; i<100; i++)
	{	
		for(int j = 0; j<50; j++)
		{
			number[j]+=s[i].at(49-j)-'0';
		}
		//std::cout<<std::endl;
	}
	int currentNum = 0;
	for(int k = 0; k<100; k++)
	{
		currentNum = number[k];
		number[k] = currentNum%10;
		number[k+1] += currentNum/10;
		std::cout<<number[k]<<std::endl;
	}
	return 0;
}

