#include<bits/stdc++.h>
using namespace std;
//Leetcode Question

//Recurssion base soln
int helper(vector<int>& s,int i){
        if(i>=s.size()) return 0;
        else{
            int ans=INT_MIN;
            ans=max(ans,s[i]-helper(s,i+1));
            if(i+1<s.size()) ans=max(ans,s[i]+s[i+1]-helper(s,i+2));
            if(i+2<s.size()) ans=max(ans,s[i]+s[i+1]+s[i+2]-helper(s,i+3));
            return ans;
        }
    }
string stoneGameIII(vector<int>& s) {
    int ans=helper(s,0);
    if(ans<0) return "Bob";
    else if(ans==0) return "Tie";
    return "Alice";
}
//Memonization based soln
int dp[500001];
int helper(vector<int>&s,int i){
    if(i>=s.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    else{
        int ans=INT_MIN;
        ans=max(ans,s[i]-helper(s,i+1));
        if(i+1<s.size()) ans=max(ans,s[i]+s[i+1]-helper(s,i+2));
        if(i+2<s.size()) ans=max(ans,dp[i]+dp[i+1]+dp[i+2]-helper(s,i+3));
        return dp[i]=ans;
    }
}
string stoneGameIII(vector<int>& s) {
    for(int i=0;i<s.size();i++)dp[i]=-1;
    int ans=helper(s,0);
    if(ans<0) return "Bob";
    else if(ans==0) return "Tie";
    return "Alice";
}
//Bottom Up approach
string stoneGameIII(vector<int>& s) {
    int n=s.size();
    vector<int>dp(n+1,0);
    int i=n-1;
    while(i>=0){
        int ans=INT_MIN;
        ans=max(ans,s[i]-dp[i+1]);
        if(i+1<s.size()) ans=max(ans,s[i]+s[i+1]-dp[i+2]);
        if(i+2<s.size()) ans=max(ans,s[i]+s[i+1]+s[i+2]-dp[i+3]);
        dp[i]=ans;
    }
    int ans=dp[0];
    if(ans<0) return "Bob";
    else if(ans==0) return "Tie";
    return "Alice";
}

int main(){
    //take input
}