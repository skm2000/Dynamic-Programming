#include<bits/stdc++.h>
using namespace std;

// problem : https://www.interviewbit.com/problems/maximum-sum-square-submatrix/
// very beautiful question

int Solution::solve(vector<vector<int> > &A, int B) {
    int r = A.size(),c=A[0].size();
    vector<vector<int>>dp(r+1,vector<int>(c+1,0));
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            dp[i][j] = A[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            int sum = INT_MIN;
            if(i-B >=0 && j-B >= 0){
                sum = max(sum,dp[i][j]-dp[i-B][j]-dp[i][j-B]+dp[i-B][j-B]);
            }
        }
    }
    return sum;
}
