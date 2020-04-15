#include<bits/stdc++.h>
using namespace std;

int expandAroundCenter(string s,int left,int right){
    if(s.length()==0 || left>right) return 0;
    while(left>=0 && right<s.length() && s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;
}
string LPSubstring(string s){
    if(s.length()==0) return "";
    int start=0,end=0;
    for(int i=0;i<s.length();i++){
        int len1=expandAroundCenter(s,i,i);
        int len2=expandAroundCenter(s,i,i+1);
        int len=max(len1,len2);
        if(len>end-start){
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }
    return s.substr(start,end-start+1);
}
int main(){
    string s = "helppreanadkada";
    cout<<LPSubstring(s)<<"\n";
}