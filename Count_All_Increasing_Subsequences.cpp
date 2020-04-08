#include<bits/stdc++.h>
using namespace std;
//O(n^2) solution
int Count_AIS(int a[],int size){
    int dp[size],ans=0;
    for(int i=0;i<size;i++){
        dp[i]=1;
    }
    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                dp[i]+=dp[j];
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<size;i++){
        ans+=dp[i];
    }
    return ans;
}

//O(n) solution : A beautiful solution
int AIS(int a[],int size){
    int count[10]={0},ans=0;
    for(int i=0;i<size;i++){
        for(int j=a[i]-1;j>=0;j--){//max 10 times
            count[a[i]]+=count[j];
        }
        count[a[i]]++;
    }
    for(int i=0;i<10;i++){
        ans+=count[i];
    }
    return ans;
}

int main(){
    int a[]={3,2,4,5,4};
    int size=sizeof(a)/sizeof(a[0]);
    cout<<Count_AIS(a,size)<<"\n";
    cout<<AIS(a,size)<<"\n";
}