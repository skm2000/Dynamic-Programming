#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,x,y,z;
	    cin>>n;
        cin>>x>>y>>z;
	    int dp[n+1];
        for(int i=0;i<=n;i++) dp[i]=-1;
	    dp[0]=0;
	    for(int i=0;i<=n;i++){
            if(dp[i]==-1) continue;
	        if(i+x<=n){
	            dp[i+x]=max(dp[i+x],dp[i]+1);
	        }
	        if(i+y<=n){
	            dp[i+y]=max(dp[i+y],dp[i]+1);
	        }
	        if(i+z<=n){
	            dp[i+z]=max(dp[i+z],dp[i]+1);
	        }
	    }
        for(int i=0;i<=n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<"\n";
	    cout<<dp[n]<<"\n";
	}
	return 0;
}