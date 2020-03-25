#include<bits/stdc++.h>
using namespace std;

int Max_ways(int coins[],int size,int sum){
    int dp[size+1][sum+1];
    for(int i=0;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=size;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=size;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=size;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    return dp[size][sum];
}

int main() {
    int coins[] = {1, 2, 3}; 
    int size = sizeof(coins)/sizeof(coins[0]);
    int sum = 4;
    cout<<Max_ways(coins,size,sum)<<"\n"; 
}