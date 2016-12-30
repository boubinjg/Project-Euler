#include <iostream>
#include <string>
//pencil and paper
int main()
{
	int count += 0;
	int store = 0;
	for(int i = 1; i<=1000; i++)
	{
		if(i == 1000)
			count+=11;
		if(i%100==0)
			count-=3;
		switch(i/100)
		{
			case 9:
				count+=4+7+3;
				break;
			case 8:
				count+=5+7+3;
				break;
			case 7:
				count+=5+7+3;
				break;
			case 6:	
				count+=3+5+3;
				break;
			case 5:
				count+=4+7+3;
				break;
			case 4:
				count+=4+7+3;
				break;
			case 3:	
				count+=5+7+3;	
			case 2:
			case 1:
			case 0:
		}
	}
	std::cout << count;
	return 0;
}

