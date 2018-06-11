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
    bool isBalanced(TreeNode* root) {
        if(Bal(root) == -1) return false;
        else return true;
    }
    int Bal(TreeNode* root) {
        if(root == NULL) return 0;
        int l = Bal(root->left);
        int r = Bal(root->right);
        if(l == -1 || r == -1) return -1;
        if(abs(l - r) > 1) return -1;
        return (1 + max(l, r));
    }
};