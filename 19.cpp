#include <iostream>
#include <string>
#include <vector>
int main()
{
	static const int months [] = {0,3,3,6,1,4,6,2,5,0,3,5};
	std::vector<int> monthTable (months,months+sizeof(months)/sizeof(months[0]));
	int total = 0, weekday = 0,yearval=0;
	for(int i = 1901; i<2001; i++)
	{
		for(int j = 0; j<12; j++)
		{
			weekday=monthTable[j]+1;
			weekday=weekday%7;	

			yearval = (i-1900)%28;
			yearval += (i-1900)/4; 
			if(i<2000)
				yearval++;
			if(i%4==0 && j<2)
				yearval--;

			weekday+=yearval;
			weekday%=7;
			if(weekday == 1)
			{
				total++;
				std::cout<<j<<"/"<<i<<std::endl;
			}
			weekday = 0;
			yearval = 0;
		}
	}
	std::cout<<total<<std::endl;
	return 0;
}

