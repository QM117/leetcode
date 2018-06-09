/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->right == NULL && root->left == NULL) return 1;
        int r = minDepth(root->right);
        int l = minDepth(root->left);
        if(r == 0 || l == 0) return l+r+1;
        if(r > l) return l + 1;
        else return r + 1;
    }
    
};
//别人的方法 递归 