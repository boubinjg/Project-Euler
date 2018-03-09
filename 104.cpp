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
bool isPan(std::string &front, std::string &back) {
    std::string match = "123456789";
    //std::cout<<"front: "<<front<<" back: "<<back<<std::endl;

    std::sort(front.begin(), front.end());
    std::sort(back.begin(), back.end());
    if(front == match && back == match)
        return true;
    return false;
}
int main() {
    long long f1 = 0, f2=1;
    long long base = 1000000000;
    std::string f1front = "0", f2front="1";
    long long f1frontInt = 0;
    for(int i = 1; i<=1000000; i++) {
        //Back:
        long long sto = (f2 + f1) % base;
        f2 = f1;
        f1 = sto;
        
        //Front:
        std::string stofront = bigInt::addInt(f1front, 
                                              f2front);
        f2front = f1front ;
        f1front = stofront;
        
        //std::cout<<"F"<<i<<": "<<f1<<std::endl;
        std::string front9(f1front.begin(), 
                            f1front.begin()+9);
        //std::cout<<"front 9: "<<front9<<std::endl;
        std::string pass = std::to_string(f1);
        if(isPan(front9, pass)) {
            std::cout<<i<<std::endl;
            break;
        }
        if(!(i % 1000))
            std::cout<<i<<std::endl;
    }   
}
