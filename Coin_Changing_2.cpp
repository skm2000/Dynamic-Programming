#include<bits/stdc++.h>
using namespace std;

int Minm_Coins(int coins[],int size,int sum) {
    int dp[size+1][sum+1];
    for(int i=0;i<=sum;i++){
        dp[0][i] = INT_MAX - 1;
    }
    for(int i=1;i<=size;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=size;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1]<=j){
                dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[size][sum];
}
int main(){
    int coins[] = {1,6,5,2,8};
    int sum = 11;
    int size = sizeof(coins)/sizeof(coins[0]);
    cout<<Minm_Coins(coins,size,sum)<<"\n";
}