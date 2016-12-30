#include <iostream>
#include <string>
#include <fstream>

int f1[10000];
int f2[10000];
int sto[10000];
int order()
{
	int currentNum = 0;
        for(int k = 0; k<10000; k++)
        {
                currentNum = f1[k];
                f1[k] = currentNum%10;
                f1[k+1] += currentNum/10;

		currentNum = f2[k];
		f2[k] = currentNum%10;
		f2[k+1] += currentNum/10;
                
        }
}
int main()
{
	for(int x = 0; x<10000; x++)
	{
		f1[x] = 0;
		f2[x] = 0;
		sto[x] = 0;
	}
	f1[1]=1;
	f2[1]=1;
	int ret = 0;
	for(int i = 1; f1[1000]<1; i++)
	{
		for(int j = 0; j<1001; j++)
		{
			sto[j] = f1[j];
			f1[j] = f1[j]+f2[j];
			f2[j] = sto[j];
		}
		order();
		
		//std::cout<<i<<std::endl;
		ret = i;
	}
	ret += 2;
	std::cout<<ret<<std::endl;;
	return 0;
}

