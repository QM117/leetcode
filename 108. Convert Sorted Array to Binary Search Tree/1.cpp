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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int L = nums.size();
        int x =  (int) L/2.0 + 1;
        TreeNode *Tree = new TreeNode(nums[x - 1]);

        
        Treebuild (Tree, nums);
     
        return Tree;
    }
    TreeNode* Treebuild(TreeNode *Tree, vector<int>& nums){
        cout << "1"<<endl;
        int L = nums.size();
        int x =  (int) L/2.0 + 1;
        int lx = (int) x/2.0 + 1;
        int rx = (int) (L - x)/2.0 + 1/2.0 + x;
        if (x - lx > 0) Tree->left = new TreeNode(nums[lx - 1]);
        if (rx - x > 0) Tree->right = new TreeNode(nums[rx - 1]);
        if (L < 2) return Tree;
        vector<int> lnums;
        vector<int> rnums;
        for (int i = 0; i < x - 1; i++)
            lnums.push_back(nums[i]);
        for (int i = 0; i < x - 1; i++)
            rnums.push_back(nums[i]); 
        Treebuild(Tree->left, lnums);
        Treebuild(Tree->right, rnums);
        return Tree;
    }
};