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
double prod(double i1, double i2, int op)
{
	switch(op)
	{
		case 0:
			//std::cout<<"+";
			return i1+i2;
		case 1:
			//std::cout<<"-";
			return i1-i2;
		case 2:
			//std::cout<<"*";
			return i1*i2;
		case 3: 
			//std::cout<<"/";
			return i1/i2;
	}
} 
bool check(int i, int j, int k, int l)
{
	if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l)
		return true;
	return false;
}
int print(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<std::endl;
	std::cout<<std::endl;
}
int perm(std::vector<int> num)
{
	double production = 0, sto = 0;
	std::vector<int> v;
	int count = 0;
	for(int i = 0; i<=4; i++)
	 for(int j = 0; j<=4; j++)
	  for(int k = 0; k<=4; k++)
	   for(int l = 0; l<=4; l++)
   	    for(int m = 0; m<4; m++)
	     for(int n = 0; n<4; n++)
   	      for(int o = 0; o<4; o++)
	       {
	      	production = 0;
		sto = 0;
		if(check(i,j,k,l) && num[i]*num[j]*num[k]*num[l] != 0)
		{ 
			//std::cout<<num[i];
			production = prod(num[i],num[j],m);
			//std::cout<<num[j];
	        	production = prod(production,num[k],n);
			//std::cout<<num[k];
			production = prod(production,num[l],o);
			//std::cout<<num[l]<<std::endl;
			if(production == (int) production && production > 0)
				v.push_back((int) production);
			
			production = 0;
			sto = 0;
			//std::cout<<num[i];		
			production = prod(num[i], num[j], m);
			//std::cout<<num[j];
			//std::cout<<" "<<num[k];	
			sto = prod(num[k], num[l], n);
			//std::cout<<num[l]<<" ";
			production = prod(sto, production, o);
			//std::cout<<std::endl;
			if(production == (int) production && production > 0)
				v.push_back((int) production); 
		} 
	       }
	std::sort(v.begin(), v.end());
	std::set<int> s(v.begin(), v.end());
	v.assign(s.begin(),s.end());
	if(v[0] == 1)
		for(int i = 0; i<v.size(); i++)
		{
			if(v[i] == i+1)
				count++;
		}
	//print(v);
	return count;
}
int main()
{
	std::vector<int> v;
	std::string ret = "";
	int max = 0, res = 0;
	for(int i = 1; i<10; i++)
	 for(int j = i+1; j<10; j++)
	  for(int k = j+1; k<10; k++)
	   for(int l = k+1; l<10; l++)
	   {
		v.clear();
	   	v.push_back(i);
		v.push_back(j);
		v.push_back(k);
		v.push_back(l);
		res = perm(v);
		if(res>max)
		{
			max = res;
			ret = std::to_string(i*1000 + j*100 + k*10 + l);	
			std::cout<<ret<<" "<<max<<std::endl;
		}
	   }
	std::cout<<ret<<std::endl;
	std::cout<<max<<std::endl;
}






