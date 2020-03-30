#include<bits/stdc++.h>
using namespace std;

int CountLPS(string s){
    int n = s.length();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(s[i] == s[j]){
                dp[i][j] = 1 + dp[i][j-1] + dp[i+1][j];
            }
            else{
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    string s = "abab";
    cout<<CountLPS(s)<<"\n";
}