#include "bigInt.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
std::string bigInt::order(std::vector<long> v)
{
        std::string ret = "";
        for(int i = 0; i<v.size(); i++)
        {
                ret.insert(0,std::to_string(v[i]%10));
                if(v.size()>i+1)
                        v[i+1]+=v[i]/10;
                else if(v[i]/10 != 0)
                        v.push_back(v[i]/10);
        }
        //std::cout<<ret<<std::endl;
        while(ret[0] == '0')
        {
                ret = ret.substr(1,ret.length()-1);
        }
        return ret;

}
std::string bigInt::subOrder(std::vector<long> v)
{
        for(int i = v.size()-1; i>0; i--)
	{
		if(v[i]<0)
		{
			v[i+1] -= 1;
			v[i] = 10+v[i];
		}
	}
	return order(v);
}
std::string bigInt::fft(std::string a, std::string b)
{
        std::vector<long> v(b.length()+a.length(),0);
        //std::cout<<v.size()<<std::endl;
        std::reverse(a.begin(),a.end());
        std::reverse(b.begin(),b.end());
        for(int i = 0; i<a.length(); i++)
        {
                for(int j = 0; j<b.length(); j++)
                {
                        v[i+j] += (b.at(j) - '0') * (a.at(i) - '0');
                }
        }
        std::string ret = order(v);
        /*while(ret[0] == '0')
        {
                ret = ret.substr(1,ret.length()-1);
        }*/
        return ret;
}
std::string bigInt::multInt(std::string s1, long long num)
{
        std::vector<long> v;
	for(int i = s1.length()-1; i>=0; i--)
        {
                v.push_back((s1.at(i)-'0')*num);
        }

        return bigInt::order(v);
}
std::string bigInt::addInt(std::string s1, std::string s2)
{
        std::vector<long> v;
        int i1 = 0, i2 = 0, it = 0;
        int ctr1 = s2.length()-s1.length();
        int ctr2 = s1.length()-s2.length();
        if(s1.length()<s2.length())
                for(int i = 0; i<ctr1; i++)
                        s1.insert(i,"0");
        else
                for(int i = 0; i<ctr2; i++)
                        s2.insert(i,"0");

        for(int i = s1.length()-1; i>=0; i--)
        {
                i1 = s1.at(i)-'0';
                i2 = s2.at(i)-'0';
                v.push_back(i1+i2);
        }
	
        return bigInt::order(v);
}
std::string bigInt::subInt(std::string s1, std::string s2)
{

	//assumes s1 >= s2
	std::vector<long> v;
	int i1 = 0, i2 = 0, it = 0;
	int ctr = s2.length()-s2.length();
	for(int i = 0; i<ctr; i++)
		s1.insert(i,"0");
	for(int i = s1.length() - 1; i>=0; i--)
	{
		i1 = s1.at(i)-'0';
		i2 = s2.at(i)-'0';
		v.push_back(i1-i2);
	}
	return bigInt::subOrder(v);
}

