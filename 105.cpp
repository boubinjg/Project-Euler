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
#include <unordered_map>

void print(std::vector<int> v){
    for(auto i : v){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
void print(std::vector<std::vector<int>> v){
    for(auto i : v)
        print(i);
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
bool isDistinct(std::vector<std::vector<int>> v){
    std::unordered_map<int, bool> map;
    for(auto i : v){
        if(map[sum(i)])
            return false;
        else
            map[sum(i)] = true;
    }
    return true;
}
bool rule2(std::vector<int> v){
    std::sort(v.begin(), v.end());
    int s1 = v[0];
    int s2 = 0;
    for(int i = 0; i<v.size()/2; i++) {
        s1 += v[i+1];
        s2 += v[v.size()-i-1];
        if(s1 <= s2)
            return false;
    }
    return true;
}
//distinct subsets of a vector
std::vector<std::vector<int>> 
distinctSubsets(std::vector<int> set) {
    int nsub  = 1<<set.size();
    std::vector<std::vector<int>> ret;
    for(int i = 1; i<nsub; i++) {
        std::vector<int> v;
        for(int k = 0; k<set.size(); k++) {
            if((1<<k) & i) {
                v.push_back(set[k]);
            }
        }
        ret.push_back(v);
    }
    return ret;
}
int main() {
    long long ret = 0;
    std::ifstream file;
    file.open("p105_sets.txt");
    std::string s;
    while(std::getline(file, s)) {
        std::vector<int> set;
        size_t pos = 0;
        while((pos = s.find(',')) != std::string::npos) {
            std::string token = s.substr(0, pos);
            set.push_back(std::stoi(token));
            s.erase(0,pos+1);
        }
        set.push_back(std::stoi(s));
        if(isDistinct(distinctSubsets(set)) && 
           rule2(set))
            ret += sum(set);
    }
    std::cout<<ret<<std::endl;
    return 0;
}
