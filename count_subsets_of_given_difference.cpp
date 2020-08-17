#include<bits/stdc++.h>
using namespace std;

// given an array a difference of subset.find the count of that difference
// approach ----------------> s1 + s2 = sum(arr) --eqn1 && s1-s2 = diff(given) ---eqn2;
// solve eqn1 & eqn2 find s1 . s1 = (sum+diff)/2
// therefore the problem reduces to count number of subset of with sum s1

int count(vector<int> &nums,int sum) {
    int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int n,diff,sum=0;
    cin>>n>>diff;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum += nums[i];
    }
    int s1 = (sum+diff)/2;
    cout<<count(nums,s1);
}