#include<bits/stdc++.h>
using namespace std;
string PrintLcs(string s1,string s2){
    int m = s1.length(),n = s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=m,j=n;
    string ans="";
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s1 = "abcdgl";
    string s2 = "abedfhl";
    cout<<PrintLcs(s1,s2)<<"\n";
}