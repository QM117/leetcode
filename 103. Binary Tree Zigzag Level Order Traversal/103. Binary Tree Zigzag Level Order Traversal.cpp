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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> R;
        vector<vector<int>> ZR;
        //R[0].push_back(2);
        if(root == NULL) return R;
        level(root, 0, R);
        
        for(int j = 0; j < R.size(); j++) {
            vector<int>T;
            T = R[j];
            if(j % 2 == 1) reverse(T.begin(),T.end());
            ZR.push_back(T);            
        }
        return ZR;
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
//和之前102 107思路一样