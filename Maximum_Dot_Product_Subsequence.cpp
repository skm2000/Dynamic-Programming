#include<bits/stdc++.h>
using namespace std;


int maxDotProduct(vector<int>& A, vector<int>& B,int size1,int size2) {
        vector<vector<int>>dp(size1,vector<int>(size2));
        for(int i=0;i<size1;i++){
            for(int j=0;j<size2;j++){
                dp[i][j]=A[i]*B[j];
                if(i>=1 && j>=1) dp[i][j] = dp[i][j]+max(dp[i-1][j-1],0);
                if(i>=1) dp[i][j] = max(dp[i][j],dp[i-1][j]);
                if(j>=1) dp[i][j] = max(dp[i][j],dp[i][j-1]);
            }
        }
    return dp[size1-1][size2-1];
}

int main(){
    int size1,size2;
    cin>>size1>>size2;
    vector<int>A(size1);
    vector<int>B(size2);
    for(int i=0;i<size1;i++){
        cin>>A[i];
    }
    for(int i=0;i<size2;i++){
        cin>>B[i];
    }
    cout<<maxDotProduct(A,B,size1,size2)<<"\n";
}