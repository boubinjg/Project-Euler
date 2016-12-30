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
int main()
{
	long r = 6, b=15, n = 21, bk, nk;
	while(nk < 1000000000000)
	{
		bk = 3*b + 2*n -2;
		nk = 4*b + 3*n -3;
		std::cout<<nk<<" "<<bk<<std::endl;
		b = bk;
		n = nk;
	}
	return 0;
}
