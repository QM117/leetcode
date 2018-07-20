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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode *temp = head->next;
        ListNode *pre;
        head->next = NULL;
        while(temp) {
            pre = temp->next;
            temp->next = head;
            head = temp;
            temp = pre;
        }
        return head;
    }
};