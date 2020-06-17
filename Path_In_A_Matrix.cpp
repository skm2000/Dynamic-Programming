#include<bits/stdc++.h>
using namespace std;
int cost[1000][1000];
void solve(int n,int cost[][1000]){
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int down=(i==n-1)?0:dp[i+1][j];
            int down_left=(i==n-1 || j==0)?0:dp[i+1][j-1];
            int down_right=(i==n-1 || j==n-1)?0:dp[i+1][j+1];
            dp[i][j]= cost[i][j]+max(down,max(down_right,down_left));
        }
    }
    int ans=dp[0][0];
    for(int i=1;i<n;i++){
        ans=max(ans,dp[0][i]);
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>cost[i][j];
            }
        }
        solve(n,cost);
    }
}