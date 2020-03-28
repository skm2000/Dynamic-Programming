#include<bits/stdc++.h>
using namespace std;
int MSIS(int a[],int size){
    int dp[size];
    for(int i=0;i<size;i++){
        dp[i] = a[i];
    }
    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j] && dp[i]<a[i]+dp[j]){
                dp[i] = a[i]+dp[j];
            }
        }
    }
    int max = dp[0];
    for(int i=1;i<size;i++){
        if(dp[i]>max){
            max = dp[i];
        }
    }
    return max;
}

int main(){
    int a[] = {1, 101, 2, 3, 100, 4, 5};  
    int size = sizeof(a)/sizeof(a[0]);
    cout<<MSIS(a,size)<<"\n";  
}