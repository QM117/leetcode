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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        return Cal(root, sum, 0);
    }
    bool Cal(TreeNode* root, int sum, int past) {
        if(root == NULL) return false;
        //cout<<root->val<<endl;
        if(root->left == NULL && root->right == NULL) {
            if(past + root->val == sum)
                return true;
            else return false;
        }
        else return (Cal(root->left, sum, past + root->val) || Cal(root->right, sum, past + root->val));
    }
};