#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
std::string subInt(std::string a, std::string b)
{
	std::vector<int> v;
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
int main()
{
	std::cout<< bigInt::fft("143672","669381")<<std::endl;;
	return 0;
}

