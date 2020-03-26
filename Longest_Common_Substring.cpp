#include<bits/stdc++.h>
using namespace std;
int LCSub(string s1,string s2){
    int m = s1.length(),n = s2.length();
    int dp[m+1][n+1],res=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                res = max(res,dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return res;
}
int main(){
    string s1 = "abcdgl";
    string s2 = "abedgl";
    cout<<LCSub(s1,s2)<<"\n";
}

