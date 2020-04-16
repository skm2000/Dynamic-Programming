#include <bits/stdc++.h>
using namespace std;

#define int long long int 

signed main(){
    int t;cin >> t;
    while( t--){
        int n , k; cin >> n >> k ;
        vector<int> prices(k); for ( int i = 0;  i < k ; i++ ) cin >> prices[i];
        vector<int> dp( 1001, INT_MAX);
        dp[0] = 0;
        for ( int i =0 ; i < k ; i ++ ){
            if  ( prices[i] == -1) continue;
            for ( int weight = i+1 ; weight <= k ; weight ++) {
                dp[ weight ] = min( dp[weight - i -  1] + prices[i] , dp[weight]);
            }
        }
        if ( dp[k] == INT_MAX){
            cout << -1 << "\n";
        }
        else cout << dp[k];
    }
}