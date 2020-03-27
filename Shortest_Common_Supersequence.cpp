#include<bits/stdc++.h>
using namespace std;

int Scs(string s1,string s2){
    int m = s1.length(),n=s2.length(),lcs;
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    lcs = dp[m][n];
    return m+n-lcs;
}
int main(){
    string s1 = "abcdgl";
    string s2 = "abedfhl";
    cout<<Scs(s1,s2)<<"\n";
}