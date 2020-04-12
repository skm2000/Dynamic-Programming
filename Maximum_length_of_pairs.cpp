int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        int dp[n+1],res=1;
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++){
            dp[i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            res=max(res,dp[i]);
        }
        if(n==0)return 0;
        else return res;
    }