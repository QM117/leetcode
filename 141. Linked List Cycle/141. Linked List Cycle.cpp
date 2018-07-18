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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *q[10000];
        q[0] = head;
        int i = 1;
        ListNode *p = head;
        if(p->next) p = p->next;
        else return false;
        while(p) {
            
            q[i++] = p;
            for(int j = 0; j < i - 1; j++)
                if(p == q[j]) return true;
            p = p->next;
        }
        return false;
    }
};