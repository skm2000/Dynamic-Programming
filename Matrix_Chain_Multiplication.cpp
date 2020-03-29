#include<bits/stdc++.h>
using namespace std;

int dp[5][5];
int MCM(int a[],int i,int j){
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX,temp_ans;
    for(int k=i;k<j;k++){
        temp_ans = MCM(a,i,k) + MCM(a,k+1,j) + a[i-1]*a[k]*a[j];
        ans = min(ans,temp_ans);
    }
    return ans;
}

int main(){
    int a[] = {1, 2, 3, 4, 3}; 
    int size = sizeof(a)/sizeof(a[0]);
    memset(dp,-1,sizeof(dp));
    cout<<MCM(a,1,size-1);
}