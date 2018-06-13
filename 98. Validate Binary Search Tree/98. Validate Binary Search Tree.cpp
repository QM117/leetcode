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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        vector<int> v;
        inorder(root, v);
        for(int i = 1; i < v.size(); i++) if(v[i] <= v[i - 1]) return false;
        return true;
    }
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};