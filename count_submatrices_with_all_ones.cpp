#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/count-square-submatrices-with-all-ones

class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        if(m.empty()) return 0;
        int sum=0;
        int dp[m.size()][m[0].size()];
        for(int i=0;i<m.size();i++) dp[i][0] = m[i][0];
        for(int i=0;i<m[0].size();i++) dp[0][i] = m[0][i];
        for(int i=1;i<m.size();i++){
            for(int j=1;j<m[0].size();j++){
                if(m[i][j] == 1) dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                else dp[i][j] = 0;
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};