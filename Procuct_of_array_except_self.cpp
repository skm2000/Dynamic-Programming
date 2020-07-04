https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/530/week-3/3300/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n+1,1);
        vector<int>right(n+1,1);
        left[0] = nums[0];
        right[n-1] = nums[n - 1 ];
        for(int i = 1;i<n;i++) {
            left[i] = left[i - 1 ] * nums[i];
        }
        for(int i = n - 2;i >= 0 ; i--) {
            right[i] = right[i+1] * nums[i];
        }
        vector<int>ans(n);
        for(int i = 0;i<n;i++) {
            if(i == 0) {
                ans[i] = right[i + 1];
            }
            if ( i == n-1 ) {
                ans[i] = left[i - 1];
            }
            if(i > 0 and i< n -1 ) {
                ans[i] = left[i - 1] * right[i + 1];
            }
            
        }
        return ans;
    }
};