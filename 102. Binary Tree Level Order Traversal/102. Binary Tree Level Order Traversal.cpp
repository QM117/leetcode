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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> R;
        //R[0].push_back(2);
        if(root == NULL) return R;
        level(root, 0, R);
        return R;
    }
    void level(TreeNode* root, int i, vector<vector<int>>& R) {
        if(root == NULL) return;
        else {
            if(R.size() < i + 1) {
                vector<int>T;
                R.push_back(T);
            }
            R[i].push_back(root->val);
            level(root->left, i + 1, R);
            level(root->right, i + 1, R);
            return; 
        }        
    }
};
//日 这里在R[i].push_back(root->val);前必须先push一个空的vector 不然算数组越界 