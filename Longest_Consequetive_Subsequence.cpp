#include<iostream>
using namespace std;
int main()
 {
     int t;
     cin>>t;
     while(t--){
         int n;
         cin>>n;
         int m[100001]={0};
         int a[n];
         for(int i=0;i<n;i++) cin>>a[i];
         for(int i=0;i<n;i++){
             m[a[i]]++;
	    }
	    int count=0,res=-1;
	    for(int i=0;i<100001;i++){
	        if(m[i]>=1)count++;
	        else count=0;
	       res=max(res,count);
	    }
	    cout<<res<<"\n";
    }
	return 0;
}