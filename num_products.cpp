// https://codeforces.com/problemset/problem/1215/B

#include<bits/stdc++.h>
using namespace std;
vector<int>d[2005];
void divisors() {
    for(int i = 1 ; i <= 2005 ; i++) {
        if(i != 1)d[i].push_back(1);
        for(int j = 2 ; j * j <= i ; j++) {
            if(i % j == 0) {
                d[i].push_back(j);
                if(i/j != j) d[i].push_back(i/j);
            }
        }
    }
}

int main() {
    #define int long long
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0 ; i < n ;i++) {
        cin>>a[i];
    }
    int a1 = 0, a2 = 0, neg = 0, pos = 0;
    for(int i = 0; i < n ;i++) {
        if(a[i] < 0) {
            swap(pos, neg);
            neg++;
            a1 += pos;
            a2 += neg;
        } else {
            pos++;
            a1 += pos;
            a2 += neg;
        }
    }
    cout<<a2 <<" "<<a1<<"\n";
}
