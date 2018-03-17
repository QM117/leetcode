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
        return  Treebuild (nums, 0, nums.size());
    }
    TreeNode* Treebuild(vector<int>& nums, int start, int end){
        if (end <= start) return NULL;
        int mid = (start + end)/2;
        TreeNode *Tree = new TreeNode(nums[mid]);   
        Tree->left = Treebuild(nums, start, mid);
        Tree->right = Treebuild(nums, mid + 1, end);
        return Tree;
    }
};