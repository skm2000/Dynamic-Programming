#include <bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/wiggle-subsequence

// O(n^2) time and o(n) space
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n == 0) return 0;
//     up[i] refers to the length of the longest wiggle subsequence obtained so far considering ith element   
        vector<int>up(n,1),down(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    up[i] = max(up[i],1+down[j]);
                }
                else if(nums[i] < nums[j]){
                    down[i] = max(down[i],1+up[j]);
                }
            }
        }
        return max(up[n-1],down[n-1]);
    }
};


// O(n) time and O(n) space

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n == 0) return 0;
//     up[i] refers to the length of the longest wiggle subsequence obtained so far considering ith element   
        vector<int>up(n,1),down(n,1);
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                up[i] = 1+down[i-1];
                down[i] = down[i-1];
            }
            else if(nums[i] < nums[i-1]){
                down[i] = 1+up[i-1];
                up[i] = up[i-1];
            }
            else{
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(up[n-1],down[n-1]);
    }
};



// O(n) ime and O(1) space
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n == 0) return 0;
        int up=1,down=1;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                up = down+1;
            }
            else if(nums[i] < nums[i-1]){
                down = up+1;
            }
        }
        return max(up,down);
    }
};