#include <bits/stdc++.h>
using namespace std;

// problem: https://leetcode.com/problems/video-stitching/

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int minm=0;
        int maxm=0;
        int total = 0;
        while(maxm < T){
            for(int i=0;i<clips.size();i++){
                int l = clips[i][0];
                int r = clips[i][1];
                if(l<=minm && r>maxm){
                    maxm = r;
                }
            }
            if(minm == maxm) return -1;
            minm = maxm;
            total++;
        }
        return total;
    }
};