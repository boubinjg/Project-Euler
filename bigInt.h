#ifndef BIGINT_H
#define BIGINT_H
#include<string>
#include<vector>
#include<algorithm>
namespace bigInt
{
	std::string addInt(std::string s1, std::string s2);
	std::string subInt(std::string s1, std::string s2);
	std::string multInt(std::string s1, long long num);
	std::string order(std::vector<long> v);
	std::string subOrder(std::vector<long> v);
	std::string fft(std::string a, std::string b);
}
#endif 

