#include<bits/stdc++.h>
using namespace std;
vector<int>v(100,0);
vector<int>dp(100,0);
vector<int>adj[100];
int largest_sum(int child,int parent) {
    dp[child] = v[child];
    int max_val = 0;
    for(auto ch : adj[child]) {
        if(ch==parent)continue;

        largest_sum(ch,child);
        max_val = max(max_val, dp[ch]);
    }
    return dp[child] += max_val;
}
int main() {
    int n;
    cin>>n;
    cout<<"Enter the nodes value\n";
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }        
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<largest_sum(1,-1)<<"\n";
}