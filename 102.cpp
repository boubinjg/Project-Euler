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
struct point{
    double x, y;
};
struct line{
    //y = mx + b
    double m, b;
};
line pointsToLine(point a, point b){

    double slope = (b.y-a.y)/(b.x-a.x);
    double intercept = b.y - slope*b.x;
    return {slope, intercept};
}
bool intOnLine(point a, point b){
    line l = pointsToLine(a,b);

    return (a.x >= 0 && b.x <= 0) ||
           (b.x >= 0 && a.x <= 0);
}
bool origin(point a, point b, point c){
    std::vector<double> ints;
    if(intOnLine(a,b)){
        ints.push_back(pointsToLine(a,b).b);
    }
    if(intOnLine(a,c)){
        ints.push_back(pointsToLine(a,c).b);
    }
    if(intOnLine(b,c)){
        ints.push_back(pointsToLine(b,c).b);
    }
	
    if(ints.size() > 2)
        std::cout<<"Greater than 3"<<std::endl;

    if(ints.size() < 2)
        return false;
    if(ints[0]>= 0 && ints[1] <= 0 || 
       ints[0]<= 0 && ints[1] >= 0){
        return true;
    } 
    return false;
}

int main() {
    int ret = 0;
    std::ifstream file;
    file.open("p102_triangles.txt");
    for(int i = 0; i<1000; i++) {
        std::string s;
        std::getline(file, s);
        size_t pos = 0;
        std::vector<double> t;
        while ((pos = s.find(',')) != std::string::npos) {
            std::string token = s.substr(0, pos);
            t.push_back(std::stoi(token));
            s.erase(0, pos + 1);
        }
        t.push_back(std::stoi(s));
        point a={t[0],t[1]}, 
              b={t[2],t[3]}, 
              c={t[4],t[5]};
        if(origin(a,b,c)){
            for(auto i : t)
                std::cout<<i<<" ";
            std::cout<<std::endl;
            ++ret;
        }
    }
    std::cout<<ret<<std::endl;
	return 0;
}

