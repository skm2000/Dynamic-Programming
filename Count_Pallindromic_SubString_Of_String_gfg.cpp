#include<bits/stdc++.h>
using namespace std;

int expandAroundCenter(string s,int left,int right){
    if(s.length()==0 || left>right) return 0;
    int ans=0;
    while(left>=0 && right<s.length() && s[left]==s[right]){
        ans++;
        left--;
        right++;
    }
    return ans;
}
int CountLPSubstring(string s){
    if(s.length()==0) return 0;
    int res=0;
    for(int i=0;i<s.length();i++){
        res+=expandAroundCenter(s,i,i);
        res+=expandAroundCenter(s,i,i+1);
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<CountLPSubstring(s)-n<<"\n";
    }
}