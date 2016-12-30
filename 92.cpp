#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
int squaredigits(int n)
{
	int ret = 0;
	std::string s = std::to_string(n);
	for(int i = 0; i<s.length(); i++)
	{
		ret += (s[i]-'0') * (s[i]-'0');
	}
	return ret;
}
int main()
{
	std::vector<int> table(10000000);
	std::vector<int> onet(10000000), ent(10000000), v;
	int n = 0, count = 0;
	for(int i = 1; i<10000000; i++)
	{
		v.clear();
		n = i;
		v.push_back(i);
		int c = 0;
		while(n != 89 && n!= 1 && !onet[n] && !ent[n] && c<10)
		{
			n = squaredigits(n);
			v.push_back(n);
			c++;
		}
		if(n == 1 || onet[n])
		{
			for(int i = 0; i<v.size(); i++)
				if(v[i] < 10000000)
					onet[v[i]] = 1;
			onet[n] = 1;
		}
		if(n==89 || ent[n])
		{
			for(int i = 0; i<v.size(); i++)
				if(v[i]<10000000)
					ent[v[i]] = 1;
			ent[n] = 1;
			count++;
		}
	}
	std::cout<<count<<std::endl;
	return 0;
}

