/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return BST(head, NULL);
    }
    TreeNode* BST(ListNode* head, ListNode* tail) {
        if(head == tail) return NULL;
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while(fast != tail&&fast->next != tail) {
            fast=fast->next->next;
            slow=slow->next;
        }
        TreeNode* Thead = new TreeNode(slow->val);
        Thead->left = BST(head, slow);
        Thead->right = BST(slow->next, tail);
        return Thead;
        
    }
};
//别人的迭代法 注意左右边界