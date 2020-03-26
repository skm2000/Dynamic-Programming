#include<bits/stdc++.h>
using namespace std;
int Minm_SubsetSum_Diff(int a[],int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += a[i];
    }
    int dp[size+1][sum+1];
    for(int i=0;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=size;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=size;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int diff;
    for(int i=sum/2;i>=0;i--){
        if(dp[size][i]==1){
            diff = sum-2*i;
            break;
        }
    }
    return diff;
}
int main(){
    int a[] = {3, 1, 4, 2, 2, 1}; 
    int size = sizeof(a)/sizeof(a[0]);
    cout<<Minm_SubsetSum_Diff(a,size)<<"\n"; 
}