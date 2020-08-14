#include <bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int minm=0;
        int maxm=0;
        int open=0;
        while(maxm < n){
            for(int i=0;i<ranges.size();i++){
                int l = i-ranges[i];
                int r = i+ranges[i];
                if(l<=minm && r>maxm){
                    maxm = r;
                }
            }
            if(minm == maxm) return -1;
            minm = maxm;
            open++;
        }
        return open;
    }
};