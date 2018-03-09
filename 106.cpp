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
std::vector<int> input;
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
bool isDisjoint(std::vector<int> v, std::vector<int> v2){
    for(auto i : v)
        for(auto j : v2)
            if(i == j)
                return false;
    return true;
}
void print(std::vector<int> v1, std::vector<int> v2){
    for(auto i : v1)
        std::cout<<i<<" ";
    std::cout<<" | ";
    for(auto i : v2)
        std::cout<<i<<" ";
    if(sum(v1) == sum(v2))
        std::cout<<"======";
    std::cout<<std::endl;
}
double choose( int n, int k){
    if(k>n) return 0;
    if(k*2 > n) k = n-k;
    if(k == 0) return 1;

    int result = n;
    for(int i = 2; i<=k; i++){
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
int main() {
    
//Tried a lot of things for this problem. Was eventually able to solve it using some catalan number BS I found on the internet for solving a similar problem.

    int ret = 0;
    int input = 12;
    int i = input/2;
    for(int i = 2; i<=input/2; i++) {
        ret += (choose(input, i) * choose(input-i, i))/2;
        double catalan = 1.0/(1.0+i) * (choose(2*i,i));
        ret -= catalan*choose(input, 2*i);
    }
    std::cout<<ret<<std::endl;
    return 0;
}
