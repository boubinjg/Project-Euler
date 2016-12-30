#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
int main()
{
 for(int a = 9; a>0; a--)
  for(int b = 10; b>0; b--)
   if(a!=b)
    for(int c = 10; c>0; c--)	
     if(a!=c && b!= c)
      for(int d = 10; d>0; d--)
       if(a!=d && b!=d && c!=d)
        for(int e = 10; e>0; e--)
         if(a!=e && b!=e && c!=e && d!=e)
          for(int f = 9; f>0; f--)
           if(a!=f && b!=f && c!=f && d!=f && e!=f)
	    for(int g = 9; g>0; g--)
             if(a != g && b != g && c != g && d != g && e != g && f != g)
              for(int h = 9; h>0; h--)
	       if(a != h && b != h && c != h && d != h && e != h && f != h && g != h)
                for(int i = 9; i>0; i--)
	         if(a!=i && b!=i && c!=i && d!=i && e!=i && f!=i && g!=i && h!=i) 
                  for(int j = 9; j>0; j--)
		   if(a!=j && b!=j && c!=j && d!=j && e!=j && f!=j && g!=j && h!=j && i!=j
                      && a<b && a<c && a<d && a<e)
		   {
            //std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<std::endl;
            	    if(a+f+g == b+g+h && a+f+g == c+h+i && a+f+g == d+i+j && a+f+g == e+j+f)
	            {
                     std::cout<<a<<" "<<f<<" "<<g<<std::endl;
	             std::cout<<b<<" "<<g<<" "<<h<<std::endl;
	             std::cout<<c<<" "<<h<<" "<<i<<std::endl;
		     std::cout<<d<<" "<<i<<" "<<j<<std::endl;
		     std::cout<<e<<" "<<j<<" "<<f<<std::endl;
                     return 0;
                    }
                   }
 return 0;
}

