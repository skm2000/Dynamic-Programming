#include<bits/stdc++.h>
using namespace std;

int CountSubsets(int a[],int size,int sum) {
    int dp[size+1][sum+1];
    for(int i=0;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=size;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=size;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
            }
            else {
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
    int a[] = { 1, 2, 3, 3 }; 
    int size = 4;
    int sum = 6;
    cout<<CountSubsets(a,size,sum)<<"\n";
}