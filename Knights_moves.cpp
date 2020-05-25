#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n ; // size of board
    cin>>n;
    int k ; // moves
    cin>>k;
    double dp[n+1][n+1][k+1];
    for(int i = 0;i < n ;i++) {
        for(int j = 0;j<n;j++) {
            dp[i][j][0] = 1 ; // propblity of staying at the board in 1 if we are having 0 moves
        }
    }
    int dx[] = {-1,1,-1,1,2,2,-2,-2};
    int dy[] = {2,2,-2,-2,1,-1,-1,1};
    for(int st = 1 ;st <= k;st++) {
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++){
                double prob = 0.0;
                for(int k = 0;k <8;k++) {
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];
                    if(next_x >=0 and next_x < n and next_y < n and next_y >=0) {
                        prob += dp[next_x][next_y][st - 1]; // summing all the probabilities of reaching (x.y) from its (next_x,next_y)
                    }
                }
                dp[i][j][st] = prob * 0.125;
            }
        }

    }
    cout<<dp[0][0][k]<<"\n";
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}