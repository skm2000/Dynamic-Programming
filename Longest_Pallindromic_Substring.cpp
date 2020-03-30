#include<bits/stdc++.h>
using namespace std;

int LPSubstring(string s){
    int n=s.length();
    int dp[n][n],ans=-1;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main(){
    string s = "abcaabaafrg";
    cout<<LPSubstring(s)<<"\n";
}