#include<bits/stdc++.h>
#define N 5
using namespace std;

int dp[N][N];

int OptimalStrategy(int coins[],int i,int j){
    //Base Cases
    if(i==j)  return coins[i];
    if(i==j+1) return max(coins[i],coins[j]);
    if(dp[i][j]==0){
        //Taking from the start
        int start = coins[i] + min(OptimalStrategy(coins,i+2,j),OptimalStrategy(coins,i+1,j-1));
        //Taking from end
        int end = coins[j] + min(OptimalStrategy(coins,i,j-2),OptimalStrategy(coins,i+1,j-1));
        //maximum of both
        dp[i][j] = max(start,end);
    }
    return dp[i][j];
}

int main(){

}