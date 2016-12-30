#include <iostream>
#include <string>
#include <fstream>

int number[302];
int order()
{
	int currentNum = 0;
        for(int k = 0; k<302; k++)
        {
                currentNum = number[k];
                number[k] = currentNum%10;
                number[k+1] += currentNum/10;
                //std::cout<<number[k]<<std::endl;
        }
}
int main()
{
	std::string s [302];
	for(int x = 0; x<302; x++)
	{
		number[x] = 0;
	}
	number[0] = 1;
	for(int i = 1; i<=1000; i++)
	{
		//if(i % 10 == 0
		for(int k = 0; k<302; k++)
			number[k]*=2;
		order();
	}
	int sum = 0;
	for(int j = 0; j<302; j++)
	{
		sum+=number[j];
	}
	std::cout<<sum<<std::endl;
	return 0;
}

