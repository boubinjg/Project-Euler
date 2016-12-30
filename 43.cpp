#include <iostream>
#include <string>
#include <vector>
std::string sSto = "0123456789";
int check(std::string num)
{
	std::vector<int> v = {2,3,5,7,11,13,17};
	for(int i = 0; i<7; i++)
	{
		//std::cout<<stoi(num.substr(i+1,3))<<" "<<v[i]<<std::endl;
		if(!(stoi(num.substr(i+1,3))%v[i]==0))
		{	
			//std::cout<<stoi((num.substr(i+1,3)))%v[i]<<std::endl;	
			return false;
		}
	}
	return true;
}
int fact(int num)
{
	int ret = 1;
	for(int i = 1; i<=num; i++)
	{
		ret *= i;
	}
	return ret;
}
int main()
{
	//first one is s, so operation is performed 1000000-1 times.
	int milStop = 3628800-1;
	long long sum = 0;
	std::string ret = "";
	//if(check("1406357289"))
	//	std::cout<<"asdfadsfadf "<<std::endl;
	for(int milnext = 1; milnext<milStop; milnext++)
	{
		int mil = milnext;
		std::string s = sSto;
		for(int i = 9 ; i>=0; i--)
		{
			ret+= s.at(mil/fact(i));
			s.erase(s.begin()+mil/fact(i));
			mil -= (mil/fact(i))*fact(i);
		}
		if(check(ret))
		{	
			sum+=stol(ret);
			std::cout<<ret<<std::endl;
		}
	//	std::cout<<sum<<std::endl;
		ret = "";
	}
	std::cout<<sum<<std::endl;
}
