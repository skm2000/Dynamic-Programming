#include<bits/stdc++.h>
using namespace std;
bool SubsetSum(int a[],int size,int sum) {
    bool dp[size+1][sum+1];
    for(int i=0;i<=sum;i++){
        dp[0][i] = false;
    }
    for(int i=0;i<=size;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=size;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1] <= j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[size][sum];
}

int main() {
    int a[] = {3, 34, 4, 12, 5, 2}; 
    int sum = 1; 
    int size = sizeof(a)/sizeof a[0];
    cout<<SubsetSum(a,size,sum)<<"\n";
}