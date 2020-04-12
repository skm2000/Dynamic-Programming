#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int dp[n+1];
	    dp[0]=0,dp[1]=1;
	    for(int i=2;i<=n;i++){
	        dp[i]=max(dp[i/2]+dp[i/3]+dp[i/4],i);
	    }
	    cout<<dp[n]<<"\n";
	}
	return 0;
}