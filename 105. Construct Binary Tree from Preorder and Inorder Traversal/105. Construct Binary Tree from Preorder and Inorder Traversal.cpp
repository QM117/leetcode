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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        Traversal(root, preorder, inorder);
        return root;
    }
private:
    void Traversal(TreeNode* root, vector<int> preorder, vector<int> inorder) {
        if(preorder.size() < 2) return;
        int location = 0;
        while(preorder[0] != inorder[location]) location++;
        if(location != 0) {
            TreeNode *l = new TreeNode(preorder[1]);
            //l->val = preorder[head + 1];
            root->left = l;
            vector<int> np,ni;
            for(int i = 0; i < location; i++){
                np.push_back(preorder[i + 1]);
                ni.push_back(inorder[i]);
                //cout<<i<<","<<location<<","<<root->val<<endl;
            }                
            Traversal(l, np, ni);
        }
        if(location != preorder.size() - 1) {
            TreeNode *r = new TreeNode(preorder[location + 1]);
            //r->val = preorder[location + 1];
            root->right = r;
            vector<int> np,ni;
            for(int i = 0; i < preorder.size() - location - 1; i++){
                np.push_back(preorder[i + 1 + location]);
                ni.push_back(inorder[i + 1 + location]);
                //cout<<i<<","<<preorder.size() - location<<","<<root->val<<endl;
            }                
            Traversal(r, np, ni);
        }
        return;
    }
};
//之前传序号出错了 这里用的最蠢的传向量 高赞解法是我一开始想的那种 分别传两个向量的头尾参数