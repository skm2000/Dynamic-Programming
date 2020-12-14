#include<bits/stdc++.h>
using namespace std;

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
    cout<<catlan(n);
}
