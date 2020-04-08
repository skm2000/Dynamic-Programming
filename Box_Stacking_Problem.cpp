#include<bits/stdc++.h>
using namespace std;

struct Box{
    int h;
    int d;
    int w;
};

bool comparator(Box b1, Box b2){
    return (b1.d*b1.w)>(b2.d*b2.w);
}
int maxStackHeight(int h[],int d[],int w[],int n){
    struct Box ini[n];
    for(int i=0;i<n;i++){
        ini[i].h=h[i];
        ini[i].d=d[i];
        ini[i].w=w[i];
    }
    struct Box b[n];
    int ind=0;
    for(int i=0;i<n;i++){
        //Original
        b[i].h = ini[i].h;
        b[i].d = max(ini[i].d,ini[i].w);
        b[i].w = min(ini[i].d,ini[i].w);
        ind++;
        //First Rotation
        b[i].h = ini[i].d;
        b[i].d = max(ini[i].h,ini[i].w);
        b[i].w = min(ini[i].h,ini[i].w);
        ind++;
        //Second Rotation
        b[i].h = ini[i].w;
        b[i].d = max(ini[i].h,ini[i].d);
        b[i].w = min(ini[i].h,ini[i].d);
        ind++;
    }
    int n=3*n;
    sort(b,b+n,comparator);

    int msh[n];//maximum stack height array
    for(int i=0;i<n;i++){
        msh[i]=b[i].h;
    }
    for (int i = 1; i < n; i++ ) 
      for (int j = 0; j < i; j++ ) 
         if ( b[i].w < b[j].w && 
              b[i].d < b[j].d && 
              msh[i] < msh[j] + b[i].h 
            ) 
         { 
              msh[i] = msh[j] + b[i].h; 
         }
    int max = -1; 
   for ( int i = 0; i < n; i++ ) 
      if ( max < msh[i] ) 
         max = msh[i]; 
  
   return max;       
}