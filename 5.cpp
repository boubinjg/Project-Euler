#include <iostream>
#include <string>
int main()
{
	double num = 1, store=0;
	bool end = false;
	while(!end)
	{
		for(int i = 1; i<=20; i++)
		{
			store = num/i;
			if(store != (int)store)
				break;
			if(i == 20)
			{
				std::cout<<std::to_string(num)<<std::endl;
				end = true;
			}
		}
		num++;
	}
	return 0;
}

