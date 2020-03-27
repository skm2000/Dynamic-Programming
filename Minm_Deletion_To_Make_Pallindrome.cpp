#include<bits/stdc++.h>
using namespace std;

int DelPallin(string s){
    int n = s.length(),lps;
    int dp[n+1][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) dp[i][j] = 1;
            else if(j<i) dp[i][j] = 0;
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    lps = dp[0][n-1];
    return n-lps;
}
int main() {
    string s = "aebcbda";
    cout<<DelPallin(s)<<"\n";
}