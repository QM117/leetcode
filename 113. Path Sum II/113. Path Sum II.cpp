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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> R;
        vector<int> V;
        path(root, sum, 0, V, R);
        return R;
    }
    void path(TreeNode* root, int sum, int past, vector<int>& V, vector<vector<int>>& R) {
        if(root == NULL) return;
        V.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
            if(past + root->val == sum)
                R.push_back(V);
        path(root->left, sum, past + root->val, V, R);
        path(root->right, sum, past + root->val, V, R);
        V.pop_back();
        return;        
    }
};