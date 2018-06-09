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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->right == NULL && root->left == NULL) return 1;
        int r = maxDepth(root->right);
        int l = maxDepth(root->left);
        if(r == 0 || l == 0) return l+r+1;
        if(r > l) return r + 1;
        else return l + 1;
    }
};