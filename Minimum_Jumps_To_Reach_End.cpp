#include<bits/stdc++.h>
using namespace std;

int Min_Jumps(int a[],int size){
    int dp[size];
    dp[0] = 0;
    for(int i=1;i<size;i++){
        dp[i] = INT_MAX;
        for(int j=0;j<i;j++){
            if(i<=j+a[j] && dp[j]!=INT_MAX){
                dp[i] = min(dp[i],1+dp[j]);
            }
        }
    }
    return dp[size-1];
}

int main(){
    int a[] = { 1, 3, 6, 1, 0, 9 }; 
    int size = sizeof(a) / sizeof(a[0]);
    cout<<Min_Jumps(a,size)<<"\n"; 
}