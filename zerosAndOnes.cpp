
// link https://leetcode.com/problems/ones-and-zeroes/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    Solution(){}
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        int dp[len+1][m+1][n+1];
        memset(dp, 0, sizeof dp);
        
        for (int i=1;i<=len;i++){
                    int ones = count(strs[i-1].begin(), strs[i-1].end(), '1');
                    int zeros = strs[i-1].size()-ones;
            for (int j=0;j<=m;j++){
                for (int k=0;k<=n;k++){

                    int res = dp[i-1][j][k];
                    if (zeros<=j && ones<=k) 
                       res = max(res, dp[i-1][j-zeros][k-ones]+1);
                    dp[i][j][k] = res;
                }
            }
        }
        
        return dp[len][m][n];
        
    }
};
int main(){
    Solution s;
    int m,n;
    cout<<"Enter the max zeros ";
    cin>>m;
    cout<<"Enter the max ones ";
    cin>>n;
    int strings;
    cout<<"Eneter the no of words ";
    cin>>strings;
    vector<string>words;
    for(int i=0;i<strings;i++) {
        string str;
        cin>>str;
        words.push_back(str);
    }
    cout<<s.findMaxForm(words,m,n)<<"\n";
}