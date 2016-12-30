#include <iostream>
#include <string>
int main()
{
	std::string s = "";
	int highPal = 0;
	for(int i = 100; i<999; i++)
	{
		for(int j = 100; j<999; j++)
		{
			s = std::to_string(i*j);
			if(s == std::string(s.rbegin(),s.rend()))
			{
				if(highPal < i*j)
					highPal = i*j;
			}
		}
	}
	std::cout <<highPal<<std::endl;
	return 0;
}

