#include<bits/stdc++.h>
using namespace std;

//used bottom-up aproach(but similar to lcs)
int longestPalindromeSubseq(string s) {
        int n=s.length();
        int dp[n+1][n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)dp[i][j]=1;
                else if(j<i)dp[i][j]=0;
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                    if(s[i]==s[j]){
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                    }
            }
        }
    return dp[0][n-1];
}

int main(){
    string s = "bbbab";
    cout<<longestPalindromeSubseq(s)<<"\n";
}