#include <bits/stdc++.h>
using namespace std;
#define int long long int
int dp[6103][6103];
signed main(){
    int t; cin >> t;
    while( t--){
        string s;
        cin >> s; string t =s;
        reverse( t.begin() , t.end());
        memset( dp , 0 , sizeof(dp));
        int n = s.size();
        for ( int i = 1 ;i  <= n ; i++ ){
            for ( int j = 1 ; j <= n ; j++ ){
                if ( s[i-1] == t[j-1]) dp[i][j] =1 + dp[i-1][j-1] ;
                dp[i][j] = max( dp[i][j] ,max( dp[i-1][j] , dp[i][j-1]));
            }
        }
        cout << n - dp[n][n] << "\n";
    }
}