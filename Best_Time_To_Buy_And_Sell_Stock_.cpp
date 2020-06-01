#include<bits/stdc++.h>
using namespace std;

//A very beautiful problem with a tweak of Kadane's algorithm.

int best_time(vector<int>&arr,int n){
    vector<int>diff(n,0);
    for(int i=1;i<n;i++){
        diff[i] = arr[i] - arr[i-1];
    }
    int max_far=diff[0],max_curr=diff[0];
    for(int i=1;i<n;i++){
        max_curr = max(max_curr+diff[i],diff[i]);
        max_far = max(max_curr,max_far);
    }
    return max_far;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<best_time(arr,n)<<"\n";
}