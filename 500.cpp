#include<iostream>
#include<vector>
#include<cmath>
bool isPrime(int num) {	
	for(int i = 2; i<=sqrt(num); i++) {
	    if(!(num % i))
	        return false;
	}
	return true;
}
int main() {
	std::vector<int> divisorBase = {2};
	long long sq = 0, number = 2;
	long long mod = 500500507;
	for(int i = 2; i<=500500; i++){
        long long last = divisorBase[divisorBase.size()-1];
        long long curPrime = last + 1;
        long long lsquare = divisorBase[sq]*divisorBase[sq];
        while(!isPrime(curPrime))
            ++curPrime;
        if(curPrime < lsquare) {
            number *= curPrime;
            number %= mod;
            divisorBase.push_back(curPrime);
        } else {
            number *= lsquare;
            number %= mod;
            divisorBase.push_back(lsquare);
            ++sq;
        }
	}
    std::cout<<"The smallest number with 2^500500 divisors is: "<<number<<" In modulo 500500507"<<std::endl;
	return 0;
}
