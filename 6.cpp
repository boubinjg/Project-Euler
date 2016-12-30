#include <iostream>
#include <string>
int main()
{
	int sum = 0;
	int squaresum = 0;
	for(int i = 1; i<=100; i++)
	{
		sum += i;
		squaresum += (i*i);
	}
	sum *= sum;
	std::cout<<sum-squaresum<<std::endl;
	return 0;
}

