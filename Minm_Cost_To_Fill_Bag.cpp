//A very very good variation of Unbounded Knapsack.#include<iostream>
#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

int minm_Cost(int cost[],int n,int W){
    vector<int>val,wt;
    int size=0;
    for(int i=0;i<n;i++){
        if(cost[i]!=-1){
            val.push_back(cost[i]);
            wt.push_back(i+1);
            size++;
        }
    }
    cout<<size<<"\n";
    n=size;
    cout<<n<<"\n";
    int dp[n+1][W+1];
    // fill 0th row with infinity 
    for (int i=0; i<=W; i++) 
        dp[0][i] = INF; 
  
    // fill 0'th column with 0 
    for (int i=1; i<=n; i++) 
        dp[i][0] = 0; 
        
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]<=j){
                dp[i][j] = min(dp[i-1][j],val[i-1] + dp[i][j-wt[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return (dp[n][W]==INF)? -1: dp[n][W]; 
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,W;
	    cin>>n>>W;
	    int cost[n];
	    for(int i=0;i<n;i++){
	        cin>>cost[i];
	    }
	    cout<<minm_Cost(cost,n,W)<<"\n";
	}
	return 0;
}