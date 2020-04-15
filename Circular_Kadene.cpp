// A very beautiful explalation given in leetcode
// https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
#include<bits/stdc++.h>
using namespace std;

int  maxMoney(int arr[], int num)
{
    int max_far=arr[0],max_curr=arr[0],min_far=arr[0],min_curr=arr[0],total=arr[0];
    for(int i=1;i<num;i++){
        max_curr=max(max_curr+arr[i],arr[i]);
        max_far=max(max_curr,max_far);
        min_curr=min(min_curr+arr[i],arr[i]);
        min_far=min(min_far,min_curr);
        total+=arr[i];
    }
    if(max_far>0){
        return max(max_far,total-min_far);
    }
    else{
        return max_far;
    }
}