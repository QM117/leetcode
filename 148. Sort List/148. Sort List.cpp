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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        int len = 0; 
        while(head != NULL) {
            head = head->next;
            len++;
        }
        sort(head, len);
    }
    void sort(ListNode* head, int len) {
        if(len == 1) return;
        int mid = len / 2;
        ListNode* tail = head;
        while(mid != 0) {
            tail = tail->next;
            mid--;
        }
        sort(head, mid);
        sort(tail, len - mid);
        merge(head, tail, len, mid);
    }
    void merge(ListNode* head, ListNode* tail, int len, int mid) {
        for(int i = 0; i < len; i++) {
            
        }
    }
    void link(ListNode* pre, ListNode* por) {
        ListNode* curr = pre->next;
        pre->next = por;
        
    }
};