#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
int tri = 0;
bool isTriangle(int num)
{
	double triNum = 0;
	for(int i = 1; triNum<num; i++)
	{
		triNum = .5*i*(i+1);
		if(triNum == num)
			return true;
	}
	return false;
}
void checkTriangle(std::string s)
{
	int count = 0;
	for(int i = 0; i<s.length(); i++)
	{
		count += s.at(i)-'A'+1;
	}
	if(isTriangle(count))
		tri++;
}
void readFile()
{
	std::ifstream infile;
	infile.open("42.txt");
	
	std::vector <std::vector <std::string> > data;
 
  	while (infile)
  	{	
    		std::string s;
    		if (!getline( infile, s )) break;

    		std::istringstream ss( s );
    		std::vector <std::string> record;

    		while (ss)
    		{
      			std::string s;
      			if (!getline( ss, s, ',' )) break;
      				record.push_back( s );
    		}

    		data.push_back( record );
  	}	
  	if (!infile.eof())
  	{
   		std::cerr << "Fooey!\n";
  	}
	for(int i = 0; i<data.size();i++)
	{	
		for(int j = 0; j<data[i].size(); j++)
		{	
			std::string item = data[i][j].substr(1,data[i][j].length()-2);
			checkTriangle(item);
			std::cout<<item<<std::endl;;
		}
	}
}
int main()
{
	readFile();
	std::cout<<tri<<std::endl;
	return 0;
}

