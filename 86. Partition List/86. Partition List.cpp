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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* H = prehead;
        while(prehead->next&&prehead->next->val<x) prehead = prehead->next;
        if(prehead->next == NULL) return head;
        ListNode* curr = prehead->next;
        ListNode* temp;
        while(curr->next) {
            if(curr->next->val < x) {
                temp = curr->next;
                if(temp->next) curr->next = temp->next;
                else curr->next = NULL;
                temp->next = prehead->next;
                prehead = prehead->next = temp;
                continue;
            }
            curr = curr->next;            
        }
        return H->next;
        
    }
};