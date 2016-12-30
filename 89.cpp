#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
#include <limits>
#include <set>
#include <fstream>
#include <sstream>
std::string efficient(int i)
{
	std::string ret = "";
       	std::string huns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	std::string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","CX"};
	std::string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
	while(i>=1000)
	{
		ret += "M";
		i-=1000;
	}
	ret += huns[i/100];
	i%=100;
	ret += tens[i/10];
	i%=10;
	ret += ones[i];
	return ret;     
}
int evaluate(std::string s)
{
	int count = 0;
	int highest = 0;
	for(int i = s.length()-1; i>=0; i--)
	{
		if(s[i] == 'M')
		{
			highest = 1000;
			count += 1000;
		}
		if(s[i] == 'D')
		{
			if(highest > 500)
				count -= 500;
			else
			{
				count += 500;
				highest = 500;
			}
		}
		if(s[i] == 'C')
		{
			if(highest  > 100)
				count -= 100;
			else
			{
				count += 100;
				highest = 100;
			}
		}
		if(s[i] == 'L')
		{
			if(highest > 50)
				count -= 50;
			else
			{
				count += 50;
				highest = 50;
			}
		}
		if(s[i] == 'X')
		{
			if(highest > 10)
				count -= 10;
			else
			{
				count += 10;
				highest = 10;
			}
		}
		if(s[i] == 'V')
		{
			if(highest > 5)
				count -= 5;
			else
			{
				count += 5;
				highest = 5;
			}
		}
		if(s[i] == 'I')
		{
			if(highest > 1)
				count -= 1;
			else
			{
				count += 1;
				highest = 1;
			}
		}
	}
	return count;
}
int main()
{
	int count = 0;
	std::ifstream infile("roman.txt");
	std::string line;
	//line = "MMMMDCCCCXXXXVI";
	while(std::getline(infile, line))
	{
		std::string best = efficient(evaluate(line));
		count += line.length() - best.length();
		std::cout<<line<<" "<<best<<" "<<line.length()-best.length()<<" ";
		std::cout<<evaluate(line)<<" "<<evaluate(best)<<std::endl;
	}
	std::cout<<count<<std::endl;
	return 0;
}

