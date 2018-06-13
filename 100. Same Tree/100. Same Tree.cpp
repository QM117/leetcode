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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL || q == NULL) return false;
        else {
            bool a;
            if(p->val == q->val) a = true;
            else a = false;
            return(a && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
    }
};