#include<bits/stdc++.h>
using namespace std;

// question link
// https://codeforces.com/problemset/problem/987/C


int main() {
    #define int long long
    int n;
    cin>>n;
    vector<int>s(n + 1), rent(n + 1);
    for(int i = 1 ; i <= n ;i++) {
        cin>>s[i];
    }
    for(int i = 1 ; i <= n ;i ++) {
        cin>>rent[i];
    }

    vector<vector<int>>dp(n+1, vector<int>(4, INT_MAX));
    for(int i = 1 ; i <= n; i++) {
        dp[i][1] = rent[i];
    }

    for(int k = 2 ; k <= 3 ;k++) {
        for(int i = 1 ; i <= n; i ++) {
            for(int j =  1 ; j < i ; j++) {
                if(s[j] < s[i]) {
                    dp[i][k] = min(dp[i][k], dp[j][k-1] + rent[i]);
                }
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 1 ; i <= n ;i++) {
        if(dp[i][3] != INT_MAX) {
            ans = min(ans, dp[i][3]);
        }
    }
    if(ans!=INT_MAX)
    cout<<ans<<"\n";
    else cout<<-1<<"\n";
}
