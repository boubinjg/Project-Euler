#include <iostream>
int main()
{
	int n1 = 1;
	int n2 = 2;
	int store = 0, count = 0;
	for(int i = 0; n2<4000000; i++)
	{
		store = n2; 
		n2 += n1;
		n1 = store;
		std::cout<<n2<<std::endl;
		if(n2 %2 == 0)
			count += n2;
	}
	std::cout << count<<std::endl;
	return 0;
}

