#include <iostream>
#include <math.h>
int main()
{
	int count = 0;
	double c = 0;
	for(int a = 0; a<1000; a++)
	{
		for(int b = 0; b<1000;b++)
		{
			c = a*a + b*b;
			c = pow(c,.5);
			if(c == (int) c)
				if(a + b + c == 1000)
					std::cout<<(int)(a*b*c)<<std::endl;	
		}
	}
	//std::cout << count << std::endl;;
	return 0;
}

