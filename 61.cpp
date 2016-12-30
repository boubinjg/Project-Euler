#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
bool square, tri, penta, hexa, hepta, octo;
int origInt = 0, sum = 0;
void isOcto(int num)
{
	for(int i = 1; i*(3*i-2) <=num; i++)
                if(i*(3*i-2) == num)
		{
                        octo = true;
			//std::cout<<"octo "<<num<<std::endl;
		}
}
void isHepta(int num)
{
	for(int i = 1; i*(5*i-3)/2 <=num; i++)
		if(i*(5*i-3)/2 == num){
			hepta = true;
			//std::cout<<"hepta "<<num<<std::endl;
		}
}
void isHexa(int num)
{
	for(int i = 1; i*(2*i-1) <=num; i++)
	{
		if(i*(2*i-1) == num){
			//std::cout<<"hexa "<<num<<std::endl;
			hexa = true;
		}
	}
}
void isPenta(int num)
{
	for(int i = 1; i*(i*3-1)/2<=num; i++)
	{	
		if(i*(i*3-1)/2 == num)
		{
			//std::cout<<"penta "<<num<<std::endl;
			penta = true;
		}
	}
}
void isSquare(int num)
{
        if(pow(num,.5) == (int)(pow(num,.5)))
        {
		//std::cout<<"square "<<num<<std::endl;
		square = true;
        }
}
void isTri(int num)
{
	for(int i = 1; i*(i+1)/2 <= num; i++)
	{
		if(i*(i+1)/2 == num)
		{
			//std::cout<<"tri "<<num<<std::endl;
			tri = true;
		}
	}
}
void check(int num)
{
	int initial = tri+square+penta+hepta+hexa+octo;
	if(penta&&tri&&square&&hepta&&octo&&hexa && (origInt/100 == num%100))
		std::cout<<"gotem "<<sum<<std::endl;
	else if(!(tri&&square&&penta&&octo&&hepta&&hexa))
	{
		num%=100;
		num*=100;
		num+=10;
		for(int i = 10; i<100 ; i++)
		{
			if(!penta)
			{
				isPenta(num);
				if(penta)
				{
					sum += num;
					check(num);
					penta = false;
					sum -= num;
				}
			}
			if(!tri)
                        {
                                isTri(num);
                                if(tri)
                                {
					sum += num;
                                        check(num);
                                        tri = false;
					sum -= num;
                                }
                        }
			if(!square)
                        {
                                isSquare(num);
                                if(square)
                                {
					sum += num;
                                        check(num);
                                        square = false;
					sum -= num;
                                }
                        }
			if(!hexa)
                        {
                                isHexa(num);
                                if(hexa)
                                {
					sum += num;
                                        check(num);
                                        hexa = false;
					sum -= num;
                                }
                        }
                        if(!hepta)
                        {
                                isHepta(num);
                                if(hepta)
                                {
					sum += num;
                                        check(num);
                                        hepta = false;
					sum -= num;
                                }
                        }
                        if(!octo)
                        {
                                isOcto(num);
                                if(octo)
                                {
					sum += num;
                                        check(num);
                                        octo = false;
					sum -= num;
                                }
                        }

			num++;
		}
	}
}
int main()
{
	for(int num = 1000; num<10000; num++)
	{	
		origInt = num;
		sum = num;
		penta = square = tri = hexa = hepta = octo = false;
		if(!penta)
                {	
			isPenta(num);
			if(penta)
				check(num);
			penta = false;
		}
        	if(!square)
		{
                	isSquare(num);
			if(square)
				check(num);
			square = false;
		}
        	if(!tri)
		{
                	isTri(num);
			if(tri)
				check(num);
			tri = false;
		}
                if(!hepta)
                {
                        isHepta(num);
                        if(hepta)
                                check(num);
                        hepta = false;
                }
                if(!hexa)
                {
                        isHexa(num);
                        if(hexa)
                                check(num);
                        hexa = false;
                }
                if(!octo)
                {
                        isOcto(num);
                        if(octo)
                                check(num);
                        octo = false;
                }


		//std::cout<<std::endl;
	}
	return 0;
}


