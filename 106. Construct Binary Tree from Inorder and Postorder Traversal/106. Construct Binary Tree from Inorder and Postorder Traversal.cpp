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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()) return NULL;
        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
        Traversal(root, inorder, postorder);
        return root;
    }
private:
    void Traversal(TreeNode* root, vector<int> inorder, vector<int> postorder) {
        if(inorder.size() < 2) return;
        int location = 0;
        while(postorder[postorder.size() - 1] != inorder[location]) location++;
        if(location != 0) {
            TreeNode *l = new TreeNode(postorder[location - 1]);
            //l->val = preorder[head + 1];
            root->left = l;
            vector<int> np,ni;
            for(int i = 0; i < location; i++){
                np.push_back(postorder[i]);
                ni.push_back(inorder[i]);
                //cout<<i<<","<<location<<","<<root->val<<endl;
            }                
            Traversal(l, ni, np);
        }
        if(location != postorder.size() - 1) {
            TreeNode *r = new TreeNode(postorder[postorder.size() - 2]);
            //r->val = preorder[location + 1];
            root->right = r;
            vector<int> np,ni;
            for(int i = 0; i < postorder.size() - location - 1; i++){
                np.push_back(postorder[i + location]);
                ni.push_back(inorder[i + 1 + location]);
                //cout<<i<<","<<postorder.size() - location - 1<<","<<postorder[i + location]<<endl;
            }                
            Traversal(r, ni, np);
        }
        return;
    }
}; 
//懒 不像改成双头尾参数的 和105思路一样