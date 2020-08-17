#include<bits/stdc++.h>
using namespace std;

// problem : https://www.lintcode.com/problem/flip-game/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string &s) {
        // write your code here
        int n=s.length();
        vector<string>ans;
        for(int i=0;i<n-1;i++){
            if(s[i] == '+' && s[i+1] == '+'){
                s[i] = s[i+1] = '-';
                ans.push_back(s);
                s[i] = s[i+1] = '+';
            }
        }
        return ans;
    }
};