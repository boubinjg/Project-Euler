#include <iostream>
bool isprime(int num)
{
	for(int i = 2; i<num; i++)
	{
		if(num%i==0)
		{
			return false;
		}
	}
	if(num<1)
		return false;
	//std::cout<<num<<std::endl;
	return true;
}
int main()
{
	int count = 0;
	int primeCount = 0, highestPrimeCount = 0, highA = 0, highB = 0;
	for(int i = -1000; i<=1000; i++)
	{
		for(int j = -1000; j<=1000; j++)
		{
			int num = 1;
			int primeCount = 0;
			while(isprime(num*num + num*i + j))
			{
				primeCount++;
				num++;
				//std::cout<<j<<num<<std::endl;
			}
			if(primeCount > highestPrimeCount)
			{
				highA = i;
				highB = j;
				highestPrimeCount = primeCount;
			}
			//std::cout<<highestPrimeCount<<std::endl;
			std::cout<<i<<" "<<j<<std::endl;
		}
	}
	std::cout << highB*highA<<" "<<highestPrimeCount<<std::endl;
	return 0;
}

