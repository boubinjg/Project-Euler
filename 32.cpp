#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
std::vector<int> saveMult(0);
int check(long mult, int i, int j)
{
	std::string m1 = std::to_string(i);
	std::string m2 = std::to_string(j);
	std::string mul = std::to_string(mult);
	
	mul+=m1;
	mul+=m2;
	std::vector<char> c(0);
	if(mul.length()==9)
	 for(int k = 0; k<9; k++)
	 {
		
		if( std::find(c.begin(), c.end(),mul.at(k)) == c.end() && mul.at(k)!='0')
		{
			c.push_back(mul.at(k));	
		}
	 }	
	if(c.size() == 9 && std::find(saveMult.begin(), saveMult.end(),mult)==saveMult.end())
	{	
		saveMult.push_back(mult);
		return mult;
	}
	else
		return 0;
}
int main()
{
	long mult = 0;
	long sum = 0;

	for(int i = 1; i<1000; i++)
		for(int j = 1; j<10000; j++)
		{
			mult = i*j;	
			sum += check(mult,i,j);
		}
	std::cout << sum;
	return 0;
}

