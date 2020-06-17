long long countWays(int m){
    long long dp[m+1]={0};
    dp[0]=1;
    for(int i=1;i<=m;i++) dp[i]+=dp[i-1];
    for(int i=2;i<=m;i++) dp[i]+=dp[i-2];
    return dp[m];
}
