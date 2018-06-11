/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        if(root->left != NULL && root->right != NULL) root->left->next = root->right;
        if(root->next != NULL) {
            TreeLinkNode *L,*R,*N;
            if(root->right != NULL) L = root->right;
            else if(root->left != NULL) L = root->left;
            else return;
            N = root->next;
            while(N != NULL) {
                if(N->left == NULL && N->right == NULL) {
                    N = N->next;
                    continue;
                }
                if(N->left != NULL) R = N->left;
                else if(N->right != NULL) R = N->right;
                L->next = R;
                //cout<<L->val<<","<<R->val<<endl;
                break;
            }            
        }
        connect(root->right);
        connect(root->left);     
    }
};