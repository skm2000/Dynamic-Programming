#include<bits/stdc++.h>
using namespace std;

int Count_All_Distinct_Occurences(string s1,string s2){
    int n=s1.length(),m=s2.length();
    if(m>n) return 0;
    int dp[n+1][m+1];
    for(int i=0;i<=m;i++) dp[0][i]=0;
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[n][m];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<Count_All_Distinct_Occurences(s1,s2)<<"\n";
    }
}
//s1=banana
//s2=ban
//therefore count=3 ie 3 distinct susequence of s2 occurs in s1;