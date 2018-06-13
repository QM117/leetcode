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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return Com(root->left, root->right);
    }
    bool Com(TreeNode* l, TreeNode* r) {
        if(l == NULL && r == NULL) return true;
        else if(l == NULL || r == NULL) return false;
        else {
            bool p;
            if(l->val == r->val) p = true;
            else p = false;
            return(p && Com(l->left, r->right) && Com(l->right, r->left));
        }
    }
};