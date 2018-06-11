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
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        return path(root, 0);
    }
    int path(TreeNode* root, int past) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return past * 10 + root->val;
        return path(root->left, past * 10 + root->val) + path(root->right, past * 10 + root->val);
    }
};
//迭代的传入值和返回值不同来进行计算