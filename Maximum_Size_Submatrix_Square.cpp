#include<bits/stdc++.h>
#define r 6
#define c 5
using namespace std;
int Max_Square(int M[r][c]){
    int dp[r][c],ans=0;
    for(int i=0;i<c;i++){
        dp[0][i] = M[0][i];
    }
    for(int i=0;i<r;i++){
        dp[i][0] = M[i][0];
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(M[i][j] == 1){
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
            }
            else dp[i][j] = dp[i-1][j-1];
            ans = max(ans,dp[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return ans;
}

int main(){
    int M[r][c] = {{0, 1, 1, 0, 1},  
                    {1, 1, 0, 1, 0},  
                    {0, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 1},  
                    {0, 0, 0, 0, 0}};
    cout<<Max_Square(M)<<"\n";                
}