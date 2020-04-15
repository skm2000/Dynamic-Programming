#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>n>>m;
        int gold[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>gold[i][j];
            }
        }
        int dp[n][m];
        int right,right_up,right_down;
        memset(dp,0,sizeof(dp));
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                right = (i==m-1)?0:dp[j][i+1];
                right_up=(i==m-1 || j==0)?0:dp[j-1][i+1];
                right_down=(i==m-1 || j==n-1)?0:dp[j+1][i+1];
                dp[j][i]=gold[j][i]+max(right,max(right_up,right_down));
            }
        }
        int ans=dp[0][0];
        for(int i=1;i<n;i++){
            ans=max(ans,dp[i][0]);
        }
        cout<<ans<<"\n";
    }
}