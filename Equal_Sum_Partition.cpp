#include<bits/stdc++.h>
using namespace std;

bool EqualSubsetSum(int a[],int size) {
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=a[i];
    }
    if(sum%2!=0) return false;
    bool dp[size+1][sum/2+1];
    for(int i=0;i<=sum/2;i++){
        dp[0][i] = false;
    }
    for(int i=0;i<=size;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=size;i++){
        for(int j=1;j<=sum/2;j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[size][sum/2];
}

int main() {

    int a[] = {3, 1, 1, 2, 2, 1};  
    int size = sizeof(a) / sizeof(a[0]);
    cout<<EqualSubsetSum(a,size)<<"\n";

}