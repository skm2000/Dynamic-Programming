#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main(){
    
    for ( int t =1; ; t++){
        string s; cin >> s;
        if ( s[0] == '-') break;
        int open = 0 ;
        int ans =  0 ; 
        int n = s.size();
        for ( int i = 0 ; i < n ; i ++){
            if ( s[i] == '}'){
                if ( !open){
                    ans++;
                    open++;
                }
                else open--;
            }
            else open++;            
        }
        cout <<t << ". " <<   ans + open/2<< "\n";
    }
}