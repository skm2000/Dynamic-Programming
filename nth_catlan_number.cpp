#include<bits/stdc++.h>
using namespace std;

// O(n^2) approach;
int nCatlan(int n) {
    vector<int>dp(n,0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

// O(n) approach using binomial coefficient

// binomial coefficent
int binomial(int n,int r){
    int res=1;
    if(r > n-r) r = n-r;
    for(int i=0;i<r;i++){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

// catlan using binomial coefficient
int catlan(int n){
    // C(n) = 1/n+1[(2*n)Cn]
    int b = binomial(2*n,n);
    return b/(n+1);
}


int main(){
    int n;
    cin >> n;
    cout<<nCatlan(n)<<"\n";
    cout<<catlan(n)<<"\n";
}