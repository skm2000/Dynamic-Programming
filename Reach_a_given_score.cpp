#include<iostream>
using namespace std;
void solve(int sum){
    int dp[sum+1]={0};
    dp[0]=1;
    for(int i=3;i<=sum;i++) dp[i]+=dp[i-3];
    for(int i=5;i<=sum;i++) dp[i]+=dp[i-5];
    for(int i=10;i<=sum;i++) dp[i]+=dp[i-10];
    
    cout<<dp[sum]<<"\n";
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int sum;
	    cin>>sum;
	    solve(sum);
	}
	return 0;
}

//similar to coin changing