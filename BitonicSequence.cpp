#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        vector<int>Lis(n+1,1); 
        vector<int>Lds(n+1,1);
        // cal longest increasing sequence
        for(int i=0;i<n;i++) {
            for(int j = i-1;j>=0;j--) {
                if(v[j]<v[i]) {
                    Lis[i] = max(Lis[i],1+Lis[j]);
                }
            }
        }
        // cal longest decreasing sequence
        for(int i=n-1;i>=0;i--) {
            for(int j = i+1;j<n;j++) {
                if(v[j]<v[i]) {
                    Lds[i] = max(Lds[i],1+Lds[j]);
                }
            }
        }
        int max_len = 1;
        for(int i=0;i<n;i++) {
            max_len = max(Lis[i]+Lds[i]-1,max_len);
        }
        cout<<max_len<<"\n";
    }
}