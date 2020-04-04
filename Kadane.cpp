#include<bits/stdc++.h>
using namespace std;

int Kadane(int a[],int size){
    int max_cur=a[0],max_far=a[0];
    for(int i=1;i<size;i++){
        max_cur=max(max_cur+a[i],a[i]);
        max_far=max(max_cur,max_far);
    }
    return max_far;
}

int main(){
    int a[]={4,-1,2,1};
    int size=sizeof(a)/sizeof(a[0]);
    cout<<Kadane(a,size)<<"\n";
}