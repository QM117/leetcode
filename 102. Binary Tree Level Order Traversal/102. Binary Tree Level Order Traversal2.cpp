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
        queue<TreeNode*>s;
        queue<int>n;
        s.push(root);
        n.push(0);
        TreeNode*P;
        int N;
        while(!s.empty()) {
            P = s.front();
            N = n.front();
            s.pop();
            n.pop();
            if(R.size()<N+1) {
                vector<int>T;
                R.push_back(T);
            }
            R[N].push_back(P->val);
            
            if(P->left != NULL) {
                s.push(P->left);
                n.push(N + 1);
            }
            if(P->right != NULL) {
                s.push(P->right);
                n.push(N + 1);
            }            
        }
        return R;
    }

};
//队列非递归方法 队列就能保证二叉树按层遍历