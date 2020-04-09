#include<bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;
int CDS(string s,int size){
    vector<int>last_char(MAX_CHAR,-1);
    int dp[size+1];
    dp[0]=1;
    for(int i=1;i<=size;i++){
        dp[i] = 2*dp[i-1];
        if(last_char[s[i-1]]!=-1){
            dp[i]=dp[i]-dp[last_char[s[i-1]]];
        }
        last_char[s[i-1]]=(i-1);
    }
    return dp[size];
}
int main(){
    string s="gfg";
    int size=s.length();
    cout<<CDS(s,size)<<"\n";
}