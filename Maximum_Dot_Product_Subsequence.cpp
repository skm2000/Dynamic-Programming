#include<bits/stdc++.h>
using namespace std;


int maxDotProduct(vector<int>& A, vector<int>& B,int size1,int size2) {
        vector<vector<int>>dp(size1,vector<int>(size2));
        for(int i=0;i<size1;i++){
            for(int j=0;j<size2;j++){
                dp[i][j]=A[i]*B[j];
                if(i>=1 && j>=1) dp[i][j] = dp[i][j]+max(dp[i-1][j-1],0);
                if(i>=1) dp[i][j] = max(dp[i][j],dp[i-1][j]);
                if(j>=1) dp[i][j] = max(dp[i][j],dp[i][j-1]);
            }
        }
    return dp[size1-1][size2-1];
}


int main(){
    int size1,size2;
    cin>>size1>>size2;
    vector<int>A(size1);
    vector<int>B(size2);
    for(int i=0;i<size1;i++){
        cin>>A[i];
    }
    for(int i=0;i<size2;i++){
        cin>>B[i];
    }
    cout<<maxDotProduct(A,B,size1,size2)<<"\n";
}

// another approach
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = int(nums1.size()), m = int(nums2.size());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j - 1], 0) + nums1[i - 1] * nums2[j - 1]);
            }
        }
        return dp[n][m];
    }
};