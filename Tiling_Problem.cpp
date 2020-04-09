#include <bits/stdc++.h> 
using namespace std;
 
int CountWays(int n, int m) 
{ 
    int dp[n + 1]; 
    dp[0] = 0; 
    for (int i = 1; i <= n; i++) { 
        if (i > m) 
            dp[i] = dp[i - 1] + dp[i - m]; 
        else if (i < m) 
            dp[i] = 1; 
        else
            dp[i] = 2; 
    } 
    return dp[n]; 
}
int main() 
{ 
    int n = 7, m = 4; 
    cout << "Number of ways = "
         << CountWays(n, m); 
    return 0; 
} 