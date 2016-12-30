#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
#include <cstdlib>
#include <ctime>
#include <limits.h> 
void print(std::vector<int> v)
{
	int highest = 0;
	int highestIndex = 0;
	int ceiling = INT_MAX;
	for(int j = 0; j<3; j++)
	{		
		for(int i = 0; i<v.size(); i++)
		{
			if(v[i]>highest && v[i]<ceiling)
			{
				highest = v[i];
				highestIndex = i;
			}
		}
		ceiling = highest;
		highest = 0;
		std::cout<<highestIndex<<std::endl;
	}
}
int choose(std::vector<int> cards)
{
	int card = cards[0];
	cards.erase(cards.begin());
	cards.push_back(card);
	print(cards);
	return card;
}
int main()
{

	std::vector<int> positions(40);
	std::vector<int> CH;
	std::vector<int> CC;
	for(int i = 0; i<16; i++)
	{
		CH.push_back(i+1);
		CC.push_back(i+1);
	}
	std::random_shuffle(CH.begin(), CH.end());
	std::random_shuffle(CC.begin(), CC.end());
	std::cout<<" "<<std::endl;
	int roll = 0, d1 = 0, d2 = 0, position = 0, card = 0;
	bool jail = false;
	int doublecount = 0;
	for(int i = 0; i<100000000; i++)
	{
		
			
		d1 = rand() %4 + 1;
		d2 = rand() %4 + 1;
		roll = d1 + d2;
		position += roll;
		position %= positions.size();
		if(d1 == d2)
			doublecount++;
		else
			doublecount =0;
		
		//community chest
		if(position == 2 || position == 17 || position == 33)
		{
			card = CC[0];
			CC.erase(CC.begin());
			CC.push_back(card);
		
			if(card == 16)
				position = 0;
			//jail
			if(card == 15)
			{
				position = 10;
				jail = true;
			}
		}
		//chance
		else if(position == 7 || position == 22 || position == 36)
		{
			card = CH[0];
			CH.erase(CH.begin());
			CH.push_back(card);
						
			if(card == 1)
				position = 0;
			//jail
			if(card == 2)
			{
				position = 10;
				jail = true;
			}
			if(card == 3)
				position = 11;
			if(card == 4)
				position = 24;
			if(card == 5)
			position = 39;
			if(card == 6)
					position = 5;
			if(card == 7 || card == 8)
			{
				if(position == 7)
					position = 15;
				if(position == 22)
					position = 25;
				if(position == 36)
						position = 5;
			}
			if(card == 9)
			{
				if(position == 7)
					position = 11;
				if(position == 22)
					position = 28;
				if(position ==36) 
					position = 11;	
			}
			if(card == 10)
				position -= 3;
		}
		//go to jail
		else if(position == 30)
		{
			position = 10;
			jail = true;
		}
		if(doublecount == 3)
			position = 10;
		positions[position]++;
	}
	print(positions);
	return 0;
}

