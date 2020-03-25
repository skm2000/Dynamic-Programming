#include<bits/stdc++.h>
using namespace std;

int rodCutting(int cost[],int len[],int size) {
    int dp[size+1][size+1];
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(len[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],cost[i-1] + dp[i][j-len[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[size][size];
}

int main() {
    int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int cost[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(cost)/sizeof(cost[0]);
    cout<<rodCutting(cost,len,size);
}
