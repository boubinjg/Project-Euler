#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
#include <limits>
#include <set>
#include <fstream>
#include <sstream>
int numtriangles(int x, int y)
{
	int triangles = 0;
	//find trianles whos right angles are 0,0
	triangles += 3*x*y;
	
	for(int i = 1; i<= 50; i++)
		for(int j = 1; j<50; j++)
		{
			int fact = Euler::GCD(i,j);
			triangles += std::min(i*fact/j, (50-j)*fact/i) * 2;
		}
	return triangles;
}
int main()
{
	std::cout<<numtriangles(50,50)<<std::endl;
	return 0;
}
