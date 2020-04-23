#include<bits/stdc++.h>
using namespace std;
//LEETCODE QUESTION

int dp[1001];
int helper(vector<int>& arr,int d,int i){
        if(dp[i]!=-1) return dp[i];
        int ans=1,n=arr.size();
        //right
        for(int j=i+1;j<=min(n-1,i+d)&&arr[i]>arr[j];j++)ans=max(ans,1+helper(arr,d,j));
        //left
        for(int j=i-1;j>=max(0,i-d)&&arr[i]>arr[j];j--)ans=max(ans,1+helper(arr,d,j));
        return dp[i]=ans;
}
int maxJumps(vector<int>& arr, int d) {
        int ans=1;
        for(int i=0;i<arr.size();i++)dp[i]=-1;
        for(int i=0;i<arr.size();i++)ans=max(ans,helper(arr,d,i));
        return ans;
}