#include<bits/stdc++.h>
using namespace std;

const int maxm=100000;
int a[3][3];
int r=3,c=3;
//One of the best problems come across.
int MinmIniPoints(int a[][3]){
    int dp[r+1];
    for(int i=0;i<=r;i++){
        dp[i]=INT_MAX;
    }
    dp[r-1]=1;
    for(int j=c-1;j>=0;j--){
        for(int i=r-1;i>=0;i--){
            dp[i]=min(dp[i],dp[i+1])-a[i][j];
            dp[i]=max(1,dp[i]);
        }
    }
    return dp[0];
}
int main(){
    int a[3][3] = { {-2,-3,3}, 
                      {-5,-10,1}, 
                      {10,30,-5} 
                    };
    cout<<MinmIniPoints(a);                  
}