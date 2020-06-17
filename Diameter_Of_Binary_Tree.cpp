//Function Written only
int helper(Node* node,int &res){
    if(node==NULL) return 0;
    int left=helper(node->left,res);
    int right=helper(node->right,res);
    int tempAns=1+max(left,right);
    int ans=max(tempAns,1+left+right);
    res=max(res,ans);
    return tempAns;
}
int diameter(Node* node) {
    int res=INT_MIN;
    helper(node,res);
    return res;
}
