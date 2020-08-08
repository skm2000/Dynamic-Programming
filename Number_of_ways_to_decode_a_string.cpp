#include<bits/stdc++.h>
using namespace std;

// similar to fibonacci
int countWays(string s){
    int n = s.length();
    int dp[n+1];
    for(int i=0;i<n;i++) dp[i] = 0;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        if(s[i-1] > '0'){
            dp[i] = dp[i-1];
        }
        if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '7')){
            dp[i] += dp[i-2];
        }
    }
    return dp[n];
}


int main(){
    string s;
    cin>>s;
    cout<<countWays(s)<<"\n";
}