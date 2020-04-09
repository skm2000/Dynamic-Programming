#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long long int dp[n+1];
	    dp[0]=0;
	    for(int i=1;i<=n;i++){
	        if(i<=3) dp[i]=1;
	        else if (i==4) dp[i]=2;
	        else dp[i] = dp[i-1]+dp[i-4];
	    }
	    cout<<dp[n]<<"\n";
	}
	return 0;
}