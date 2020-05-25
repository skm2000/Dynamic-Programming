#include<bits/stdc++.h>
using namespace std;

int maxUncrossedLines(vector<int>& A, vector<int>& B,int n,int m) {
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}


int main(){
    int m,n;
    cin>>m>>n;
    vector<int>A(m),B(n);
    for(int i=0;i<m;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    cout<<maxUncrossedLines(A,B,m,n)<<"\n";
}