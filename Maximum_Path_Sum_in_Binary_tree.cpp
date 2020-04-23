//Only function Written
class Solution {
    int maxToRoot(TreeNode *root, int &re) {
        if (!root) return 0;
        int l = maxToRoot(root->left, re);
        int r = maxToRoot(root->right, re);
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        re=max(re,l+r+root->val);
        return root->val += max(l, r);
    }
public:
    int maxPathSum(TreeNode *root) {
        int re = -2147483648;
        maxToRoot(root, re);
        return re;
    }
};