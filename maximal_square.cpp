#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int res=0;
        vector<vector<int>>m(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == '0') m[i][j]=0;
                else {
                    m[i][j] = 1;
                    res = 1;
                }
            }
        }
        int dp[m.size()][m[0].size()];
        for(int i=0;i<matrix.size();i++) dp[i][0] = m[i][0];
        for(int i=0;i<matrix[0].size();i++) dp[0][i] = m[0][i];
        for(int i=1;i<m.size();i++){
            for(int j=1;j<m[0].size();j++){
                if(m[i][j] == 1) dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                else dp[i][j] = 0;
                res = max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};