#include<bits/stdc++.h>
using namespace std;
int getMinimumSquares(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=n;i++){
        dp[i]=i;//marking with the maximum
        for(int p=1;p<=ceil(sqrt(i));p++){//maximum it can go is ceil(sqrt(n)
            int temp=p*p;
            if(temp>i) break;
            dp[i]=min(dp[i],1+dp[i-temp]);
        }
    }
    return dp[n];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<getMinimumSquares(n)<<"\n";
    }
}