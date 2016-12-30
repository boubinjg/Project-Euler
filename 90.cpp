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
void print(std::vector<int> v)
{
	for(int i = 0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
}
bool check(std::vector<int> d1, std::vector<int> d2)
{
	int num = 0;
	for(int i = 1; i<10; i++)
	{
		num = i*i;
		if((std::find(d1.begin(),d1.end(),num/10) != d1.end() &&
	           std::find(d2.begin(),d2.end(),num%10) != d2.end()))
		{
		}
		else if(std::find(d2.begin(),d2.end(),num/10) != d2.end() &&
	                std::find(d1.begin(),d1.end(),num%10) != d1.end() )
		{
				
		}
		else 
		{
			//print(d1);
			//print(d2);
			//std::cout<<std::endl;
			return false;
		}
	}
	return true;
	
}
std::vector<int> addnine(std::vector<int> v)
{
	if(std::find(v.begin(),v.end(), 6) != v.end())
		v.push_back(9);
	if(std::find(v.begin(),v.end(), 9) != v.end())
		v.push_back(6);
	return v;
}
int main()
{
	int count = 0;
	std::vector<int> d1, d2;
	for(int i = 0; i<10; i++)
	 for(int j = i+1; j<10; j++)
	  for(int k = j+1; k<10; k++)
           for(int l = k+1; l<10; l++)	
            for(int m = l+1; m<10; m++)
	     for(int n = m+1; n<10; n++)
	     {
		for(int a = 0; a<10; a++)
	 	 for(int b = a+1; b<10; b++)
	  	  for(int c = b+1; c<10; c++)
           	   for(int d = c+1; d<10; d++)	
            	    for(int e = d+1; e<10; e++)
	     	     for(int f = e+1; f<10; f++)
	     	     {
			d1.clear();
			d2.clear();
			d1.push_back(a);
			d1.push_back(b);
			d1.push_back(c);
			d1.push_back(d);
			d1.push_back(e);
			d1.push_back(f);
			
			d2.push_back(i);
			d2.push_back(j);		
			d2.push_back(k);		
			d2.push_back(l);		
			d2.push_back(m);			
			d2.push_back(n);
			
			d1 = addnine(d1);	
			d2 = addnine(d2);
			if(check(d1,d2))
				count++;
	             }
	     }
	//all possibilities explored twice so count/2 is answer
	count /= 2;
	std::cout<<count<<std::endl;
	return 0;
}

