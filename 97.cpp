#include <iostream>
#include <string>
int main()
{
	long num = 28433;
	for(int i = 1;i<=7830457;i++ )
	{
		num*=2;
		num%=10000000000;
	}
	std::cout<<num+1;
	return 0;
}

