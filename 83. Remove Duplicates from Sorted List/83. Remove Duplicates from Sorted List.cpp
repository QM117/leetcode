/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* p = head;
        while(p->next) {
            if(p->next->val == p->val && p->next->next) p->next = p->next->next;
            else if(p->next->val == p->val && p->next->next == NULL) p->next =  NULL;
            else p = p->next;
        }
        return head;
    }
};