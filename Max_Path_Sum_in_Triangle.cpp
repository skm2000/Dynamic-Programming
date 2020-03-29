#include<bits/stdc++.h>
#define N 4
using namespace std;

int Max_Sum_Tri(int t[][N],int m,int n){
    for(int i=m-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            t[i][j] = max(t[i+1][j],t[i+1][j+1])+t[i][j]; 
        }
    }
    return t[0][0];
}

int main(){
    int t[N][N] = { {3,0,0,0},
                    {7,4,0,0},
                    {2,4,6,0},
                    {8,5,9,3} };
    cout<<Max_Sum_Tri(t,4,4)<<"\n";                   
}

