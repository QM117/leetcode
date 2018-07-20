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
        if(head == NULL) return NULL;
        ListNode *fast, *slow, *temp;
        fast = head;
        slow = head;
        while(fast&&fast->next) {
            fast=fast->next->next;
            slow=slow->next;
        }
        TreeNode* Thead = new TreeNode(slow->val);
        TreeNode* Ttemp;
        temp = slow -> next;
        Ttemp = Thead;
        while(temp) {
            Ttemp->right = new TreeNode(temp->val);
            Ttemp = Ttemp->right;
            temp = temp->next;
        }
        if(head != slow) Thead->left = new TreeNode(head->val);
        else return Thead;
        Ttemp = Thead->left;
        temp = head->next;
        while(temp != slow) {
            Ttemp->right = new TreeNode(temp->val);
            Ttemp = Ttemp->right;
            temp = temp->next;
        }
        return Thead;
    }
};
//高度平衡二叉搜索树不唯一 我觉得我这样也对