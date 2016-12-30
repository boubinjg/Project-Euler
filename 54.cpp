#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <cstring>
int colCount = 0;
int p1arr [100] = {0};
int p2arr [100] = {0};
int calcHand(std::string s)
{
	bool two = false, twoPair = false, three = false, four = false, straight = false, broadway = false, flush = true;
	int arr[100] = {0};
	for(int i = 0; i<s.length(); i+=3)
	{
		if(s.at(i)-'2' < 10)
			arr[s.at(i)-'0']++;
		else if(s.at(i) == 'T')
			arr[10]++;
		else if(s.at(i) == 'J')
                        arr[11]++;
		else if(s.at(i) == 'Q')
                        arr[12]++;
		else if(s.at(i) == 'K')
                        arr[13]++;
		else if(s.at(i) == 'A')
                        arr[14]++;
		
	}
	
	for(int i = 0; i<15; i++)
	{	
		if(arr[i] == 2)
		{	
			if(two)
				twoPair = true;
			two = true;
		}
		if(arr[i] == 3)
			three = true;
		if(arr[i] == 4)	
			four = true;
		//std::cout<<arr[i];
	}
	
	if(!two || !three || !four)
	{
		int count = 0;
		for(int i = 0; i<15; i++)
		{
			if(count == -1)
				break;
			if(arr[i] == 1)
				count++;
			if(arr[i]==0 && count>0)
				count = -1;
			if(count == 5)
			{
				if(i == 14)
					broadway = true;
				straight = true;
			}
			
		}
	}
	char suit = s.at(1);
	for(int i = 1; i<s.length(); i+=3)
	{
		if(suit != s.at(i))
		{
			flush = false;
		}
	}
	
	if(flush&&broadway&&straight)
		return 9;
	else if(flush&&straight)
		return 8;
	else if(four)
		return 7;
	else if(two&&three)
		return 6;
	else if(flush)
		return 5;
	else if(straight)
		return 4;
	else if(three)
		return 3;
	else if(twoPair)
		return 2;
	else if(two)
		return 1;
	
	return 0;
}
void makeArr(std::string s, int num)
{
	int arr[100] = {0};
        for(int i = 0; i<s.length(); i+=3)
        {
                if(s.at(i)-'2' < 10)
                        arr[s.at(i)-'0']++;
                else if(s.at(i) == 'T')
                        arr[10]++;
                else if(s.at(i) == 'J')
                        arr[11]++;
                else if(s.at(i) == 'Q')
                        arr[12]++;
                else if(s.at(i) == 'K')
                        arr[13]++;
                else if(s.at(i) == 'A')
                        arr[14]++;

        }
	if(num == 1)
		std::memcpy(p1arr, arr, sizeof(arr));
	else
		std::memcpy(p2arr, arr, sizeof(arr));

}
void highCard(std::string p1, std::string p2)
{
	std::cout<<"high"<<std::endl;
	for(int i = 0; i<100; i++)
	{
		p1arr[1] = 0;
		p2arr[2] = 0;
	}
	makeArr(p1,1);
	makeArr(p2,2);
	
	for(int i = 15; i>=0; i--)
	{
		std::cout<<i<<std::endl;
		if(p1arr[i]>0 && p2arr[i] == 0)
		{		
			std::cout<<"p1win"<<std::endl;
			colCount++;
			break;
		}
		else if(p2arr[i]>0 && p1arr[i] == 0)
		{
			std::cout<<"p2win"<<std::endl;	
			break;
		}
	}
    
}
void highPair(std::string p1, std::string p2)
{
	std::cout<<"pair"<<std::endl;
        for(int i = 0; i<100; i++)
        {
                p1arr[1] = 0;
                p2arr[2] = 0;
        }
        makeArr(p1,1);
        makeArr(p2,2);
	int origCount = colCount;
        for(int i = 15; i>=0; i--)
        {
                std::cout<<i<<std::endl;
                if(p1arr[i]==2 && p2arr[i] != 2)
                {
                        std::cout<<"p1win"<<std::endl;
                       	colCount++;
			break;
                }
                else if(p2arr[i]==2 && p1arr[i] != 2)
                {
                        std::cout<<"p2win"<<std::endl;
                        origCount++;
			break;
                }
        }
	if(origCount == colCount)
		highCard(p1,p2);

}
void check(std::string s)
{
	std::string p1 = s.substr(0,14);
	std::string p2 = s.substr(15,14);
	int count=0;
	//std::cout<<p1<<std::endl;
	int p1v = calcHand(p1);
	//std::cout<<p2<<std::endl;;
	int p2v = calcHand(p2);
	//std::cout<<p1v<<" "<<p2v<<std::endl;
	if(p2v == p1v)
	{
		if(p1v == 0)
			highCard(p1,p2);
		else
			highPair(p1,p2);
	}
	else if(p1v>p2v)
		colCount++;
	//std::cout<<colCount<<std::endl;
}
void readFile()
{
	std::ifstream infile;
	infile.open("54.txt");
	
	std::vector <std::vector <std::string> > data;
 
  	while (infile)
  	{	
    		std::string s;
    		if (!getline( infile, s )) break;

    		std::istringstream ss( s );
    		std::vector <std::string> record;
		
		check(s);
    	
  	}	
  	if (!infile.eof())
  	{
   		std::cerr << "Fooey!\n";
  	}
}
int main()
{
	readFile();
	//std::string a = "8C 8S KC 9H 4S 8D 8S 5D 3S AC";
	//check(a);
	std::cout<<colCount<<std::endl;
	return 0;
}

