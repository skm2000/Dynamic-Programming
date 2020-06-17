#include<bits/stdc++.h>
using namespace std;

// Problem Statement : https://leetcode.com/problems/russian-doll-envelopes/

//Similar to LIS with a tweak.
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(),envelopes.end());
    int n=envelopes.size(),res=1;
    vector<int>dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
        res = max(res,dp[i]);
    }
    if(n==0) return 0;
    else return res;
}


