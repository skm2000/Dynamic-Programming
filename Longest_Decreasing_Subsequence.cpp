#include<bits/stdc++.h>
using namespace std;

int LDS(int a[],int size){
    int dp[size+1],res=1;
    for(int i=0;i<size;i++){
        dp[i] = 1;
    }
    for(int i=size-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
        res = max(res,dp[i]);
    }
    return res;
}
int main(){
    int a[] = {10,9,2,5,3,7,101,18};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<LDS(a,size)<<"\n";
}