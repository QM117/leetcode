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
        vector<int> sum;
        path(root, sum, 0);
        int S = 0;
        for(int i = 0; i < sum.size(); i++) {
            S+=sum[i];
            //cout<<sum[i]<<endl;
        }
        return S;
    }
    void path(TreeNode* root, vector<int>& sum, int past) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            sum.push_back(past + root->val);
            return;
        }
        path(root->left, sum, (past + root->val)*10);
        path(root->right, sum, (past + root->val)*10);        
    }
};