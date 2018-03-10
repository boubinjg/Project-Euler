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
struct edge{
    long int u, v, weight;  
};
std::vector<edge> prim(std::vector<edge> e){
    std::vector<edge> eprime;
    std::unordered_map<int, bool> v;
    v[0] = true;
    for(int i = 1; i<40; i++){
        edge min = {-1, -1, INT_MAX};
        for(auto i : e){
            if(v[i.v] && !v[i.u] && min.weight > i.weight)
                min = i;
        }
        v[min.u] = true;
        eprime.push_back(min);
    }
    std::cout<<eprime.size()<<std::endl;
    return eprime;
}
int main()
{
	std::ifstream file("p107_network.txt");
    std::string line;
    std::vector<std::vector<int>> graph;
	while(std::getline(file, line)) {
        std::vector<int> row;
        size_t pos = 0;
        while((pos = line.find(',')) != std::string::npos){
            std::string token = line.substr(0, pos);
            if(token == "-")
                row.push_back(-1);
            else
                row.push_back(std::stoi(token));
            line.erase(0, pos+1);
        }
        if(line == "-")
            row.push_back(-1);
        else
            row.push_back(std::stoi(line));
        graph.push_back(row);
    }
    int totalWeight = 0;
    std::vector<edge> e;
    for(auto it = graph.begin(); it != graph.end(); ++it){
        for(auto jt = (*it).begin(); jt != (*it).end(); ++jt){
            if(*jt != -1){
                e.push_back({it-graph.begin(),
                             jt - (*it).begin(),
                             *jt});
                totalWeight += *jt;
            }
        }
    }
    totalWeight /= 2;
    auto ep = prim(e);
    int mst = 0;
    for(auto i : ep){
        std::cout<<i.u<<" "<<i.v<<" "<<i.weight<<std::endl;
        mst += i.weight;
    }
    std::cout<<totalWeight<<" "<<mst<<std::endl;
    std::cout<<totalWeight - mst << std::endl;
	return 0;
}

