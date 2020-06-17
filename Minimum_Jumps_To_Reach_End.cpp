#include<bits/stdc++.h>
using namespace std;

//o(n^2)
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

//O(n)
int minJumps(int a[],int n){
    if(n<=1) return 0;
    if(a[0]==0) return -1;
    int maxReach=a[0];
    int step=a[0];
    int jump=1;
    int i=1;
    for(int i=1;i<n;i++){
        if(i == n-1) return jump;
        maxReach=max(maxReach,i+a[i]);
        step--;
        if(step == 0){
            jump++;
            if(i>=maxReach) return -1;
            step=maxReach-i;
        }
    }
    return -1;
}

int main(){
    int a[] = { 1, 3, 6, 1, 0, 9 }; 
    int size = sizeof(a) / sizeof(a[0]);
    cout<<Min_Jumps(a,size)<<"\n"; 
}
