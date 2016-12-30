#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <algorithm>
int main()
{
	bool found = false;
    	std::string str; 
	int perm = 0;
	int count = 0;
	int i = 103, j = 111, k = 100;
	char letter;
	for(i = 97; i<123 && !found; i++)
	{ 
	 for(j = 97; j<123 && !found; j++)
	 {
	  for(k = 97; k<123 && !found; k++)
	  {
		count = 0;
		std::ifstream file("59.txt");
		char one = i, two = j, three = k;
		for(int l = 0; l<1201; l++)
		{	
			std::getline(file,str,',');
			if(perm%3 == 0)
				letter = i xor stoi(str);
			else if(perm%3 == 1)
				letter = j xor stoi(str);
			else
				letter = k xor stoi(str);
			if((letter == 41 || letter == 40 || letter == 44) || (letter == 46 || letter == 39) || 
			   (letter == 34 || letter == 33 || letter == 32) || (letter > 47 && letter < 60) ||
			   (letter > 64 && letter <91) || (letter > 96 && letter< 123))
			{	
				std::cout<<letter;
				count+= (int)letter;
			}
			else
			{
				std::cout<<(int)letter;
				break;
			}
			perm++;
		}
		std::getline(file,str,',');
		
		if(file.eof())
		{
			found = true;
			std::cout<<"found"<<std::endl;
		}
		std::cout<<count<<std::endl;
	  } 
         }
	 std::cout<<letter<<std::endl;
        }
	std::cout<<count<<std::endl;
	return 0;
}

