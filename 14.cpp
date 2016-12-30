#include <iostream>
#include <string>
int main()
{
	int highNum = 0;
	int highCount = 0, count = 0;
	for(int j = 1; j<1000000; j++)
	{
		count = 0;
		long i = j;
		while(i != 1)
		{
			if(i%2 == 0)
				i/=2;
			else
				i=(i*3)+1;
			count++;
			if(i==1)
				break;
			//std::cout<<j<<std::endl;
			if(count>1000000)
			{
				std::cout<<"aaaaaaaaaaaaaaaaaaaaaaa "<<i<<std::endl;
			}
		}
		if(count>highCount)
		{
			highNum = j;
			highCount = count;
			std::cout<<j<<std::endl;
		}
		//std::cout<<i<<std::endl;
	}
	std::cout<<highNum<<std::endl;
	return 0;
}

