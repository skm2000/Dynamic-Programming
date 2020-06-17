/*

HINT 

Testcases
25114
1111111111
3333333333
109
20201
1013
211003
100
21103
101230

Output
6
89
1
1
1
2
0
0
2


*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
signed main()
{
    while (true)
    {
        string s;
        cin >> s;
        if (s == "0")break;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n-1]=1;
        if ( n>=2){
            int x = (s[n-2] - '0') * 10 + s[n-1] - '0';
            if ( x >= 10 && x <= 26 ) dp[n-2] =1;
        }
        int np = 0;
        for (int i = n - 2; i >= 0; i--){
            if ( s[i+1] == '0' ) {
                if (s[i] == '0') np = 1;
                dp[i] += dp[i+2];
                continue;
            }
            dp[i] += dp[i + 1];
            int x = (s[i] - '0') * 10 + s[i + 1] - '0';
            if (x >= 10 && x <= 26 && s[i+2] != '0')
                dp[i] +=  dp[i + 2];
        }
        if ( np) cout << 0 << "\n";
        else cout << dp[0] << "\n";
    }
}