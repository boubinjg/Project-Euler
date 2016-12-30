#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool isPrime(int num)
{
	for(int i = 2; i<num; i++)
		if(num%i == 0)
			return false;
	return true;
}
int main()
{
	int count = 0, consec = 0, ret = 0;
	//std::vector<int> v;
	for(int i = 2; i<1000000; i++)
	{
		//std::cout<<i%2<<std::endl;
		for(int j = 2; j<=i/2&&!isPrime(i); j++)
		{
			if(i%j == 0 && isPrime(j))
			{
				/*if(std::find(v.begin(), v.end(), j) == v.end())
				{	
					v.push_back(j);	
					count++;
					std::cout<<j<<" ";
				}*/
				count++;
			}	
		}
		//std::cout<<count<<std::endl;
		if(count >= 4)
                        consec++;
                else
                	consec = 0;
                if(consec == 4)
                {
                	ret = i-3;
			break;
                }
		count = 0;
                //if(consec == 0)
                //        v.clear();
		std::cout<<i<<std::endl;
	}
	std::cout<<ret<<" "<<ret+1<<" "<<ret+2<<" "<<ret+3<<std::endl;
	//for(int i = 0; i<v.size(); i++)
	//	std::cout<<v[i]<<std::endl;
	return 0;
}

