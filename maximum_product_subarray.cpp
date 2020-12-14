#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         almost similar to kadane
        int n=nums.size(),maxPro=1,minPro=1,best=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                swap(maxPro,minPro);
            }
            maxPro = max(maxPro*nums[i],nums[i]);
            minPro = min(minPro*nums[i],nums[i]);
            best = max(best,maxPro);
        }
        return best;
    }
};