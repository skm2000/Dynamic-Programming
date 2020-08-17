#include <bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/nim-game

//  n > 10^9 won't work, O(n) solution
class Solution {
public:
    bool canWinNim(int n) {
        if(n <= 3) return true;
        bool dp[n+1];
        dp[0]=false;
        dp[1]=true,dp[2]=true,dp[3]=true;
        for(int i=4;i<=n;i++){
            dp[i] = !(dp[i-1] && dp[i-2] && dp[i-3]);
        }
        return dp[n];
    }
};

//  O(1) solution

class Solution {
public:
    bool canWinNim(int n) {
        return !(n%4 == 0);
    }
};