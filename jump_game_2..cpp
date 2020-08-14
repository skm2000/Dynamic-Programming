#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/jump-game-ii/
// dp+greedy(range-based)

class Solution {
public:
    int jump(vector<int>& nums) {
       int pos=0,des=0,jump=0;
        for(int i=0;i<nums.size()-1;i++){ //nums.size()-1 is done coz we dont need the last index
            des = max(des,i+nums[i]);
            if(pos == i){
                pos = des;
                jump++;
            }
        }
        return jump;
    }
};