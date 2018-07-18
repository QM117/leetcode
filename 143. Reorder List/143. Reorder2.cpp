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
    void reorderList(ListNode* head) {
        ListNode* fast, *slow, *phead, *temp;
        if(!head) return;
        if(head->next && head->next->next) {
            fast = head;
            slow = head;
        }
        else return;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next) fast = fast->next;
        phead = slow->next;
        slow->next = NULL;
        temp = NULL;
        cout<<phead->val<<endl;
        ListNode* pre1, *pre2;
        while(phead) {
            if(phead->next) pre1 = phead->next;
            else {
                phead->next = temp;
                break;
            }
            phead->next = temp;
            temp = phead;
            phead = pre1;  
        }
        temp = head;
        while(temp && phead) {
            pre1 = temp->next;
            pre2 = phead->next;
            temp->next = phead;
            temp->next->next = pre1;
            temp = pre1;
            phead = pre2;            
        }

    }
};