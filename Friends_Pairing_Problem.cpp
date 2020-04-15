#include<iostream>
#define m 1000000007
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long long int dp[n+1];
	    for(int i=0;i<=n;i++){
	        if(i<=2) dp[i]=i;
	        else{
	            dp[i]=((dp[i-1]%m)+((i-1)%m*(dp[i-2]%m))%m)%m;
	        }
	    }
	    cout<<dp[n]<<"\n";
	}
	return 0;
}