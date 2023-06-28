#include <iostream>
using namespace std;


bool isLimitValid(vector<unsigned long>&requirements, unsigned long m, unsigned long k){
    unsigned int total=0;
    for(auto amount:requirements){
        total += min(amount,k);
    }
    return total<=m;
}


unsigned long getMaxLimit(vector<unsigned long>&requirements, unsigned long m){
    unsigned long s = 0;
    unsigned long e = m;
    unsigned long maxLimit=0;
    while(s<=e){
        unsigned long mid = s + (e-s)/2;
        if(isLimitValid(requirements,m,mid)){
            maxLimit=mid;
            s = mid+1;
        }
        else e = mid-1;
    }
    return maxLimit;
}


int main() {
    unsigned long n, m;
    cin >> n >> m;
    vector<unsigned long> requirements;
    for(unsigned long i=0;i<n;i++){
        unsigned long requirement;
        cin >> requirement;
        requirements.emplace_back(requirement);
    }
    cout << getMaxLimit(requirements,m);
    return 0;
}
