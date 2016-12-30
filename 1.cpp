#include <iostream>
int main()
{
	int count = 0;
	for(int i = 0; i<1000; i++)
	{
		if(i%3 == 0 || i%5 == 0)
			count += i;	
	}
	std::cout << count;
	return 0;
}

