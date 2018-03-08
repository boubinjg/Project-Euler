#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include "bigInt.h"
#include "soe.h"
#include "Euler.h"
#include <climits>
#include <set>
#include <fstream>
#include <sstream>
void print(std::vector<int> v){
    for(auto i : v){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
int sum(std::vector<int> v){
    return std::accumulate(v.begin(), v.end(), 0);
}
bool test(std::vector<int> l, std::vector<int> r){
    if(sum(l) == sum(r))
        return false;
    else if(l.size() > r.size() && sum(l) <= sum(r))
        return false;
    return true;
}
void perm(std::vector<int> set){
    int minDiff = INT_MAX;
    std::vector<int> minL, minR;
    for(int i = 0; i<set.size(); i++){
        std::vector<int> v = set;
        do{
            std::vector<int> l(v.begin(), v.begin()+i),
                             r(v.begin()+i, v.end());
            if(!test(l,r)){
                std::cout<<"F"<<std::endl;
                print(l);
                print(r);
            } else if(abs(sum(l) - sum(r)) < minDiff) {
                minDiff = abs(sum(l) - sum(r));
                minL = l;
                minR = r;
            }
        } while(std::next_permutation(v.begin(), v.end()));
    }
    std::cout<<minDiff<<std::endl;
    print(minL);
    print(minR);
}
int main()
{
    std::vector<int> set{20, 31, 38, 39, 40, 42, 45};
    perm(set);
    std::cout<<sum(set)<<std::endl;
	//NOTE: This problem was solved trivially. The hint on 
	//the problem page was apparently the answer. I wrote
	//these functions to check it's validity as a starting
	//place and entered it as a check. Looks like it's 
	//correct.
	return 0;
}

