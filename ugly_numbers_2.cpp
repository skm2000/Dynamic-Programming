#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0) return 0;
        if(n == 1) return 1;
        int t2=0,t3=0,t5=0;
        vector<int>k(n);
        k[0]=1;
        for(int i=1;i<n;i++){
            k[i] = min(2*k[t2],min(3*k[t3],5*k[t5]));
            if(k[i] == 2*k[t2]) t2++;
            if(k[i] == 3*k[t3]) t3++;
            if(k[i] == 5*k[t5]) t5++;
        }
        return k[n-1];
    }
};