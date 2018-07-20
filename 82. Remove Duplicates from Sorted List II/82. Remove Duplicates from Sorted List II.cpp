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
        ListNode* phead = new ListNode(0);
        phead->next = head;
        ListNode* pre = phead;
        ListNode* p = head;
        int x = head->val;
        while(p&&p->next) {
            if(p->next->val == x && p->next->next) {
                //cout<<x<<endl;
                //if(p->next) cout<<p->val<<p->next->val<<endl;
                while(p->next&&p->next->val == x) p = p->next;
                //if(p->next) cout<<p->val<<p->next->val<<endl;
                if(p->next) phead->next = p->next;
                else phead->next =NULL;
                //phead = phead->next;
                p=p->next;
                if(p) x = p->val;
            }
            else if(p->next->val == x && p->next->next == NULL) {phead->next =  NULL; break;}
            else {
                p = p->next;
                x = p->val;
                phead = phead->next;
            }
        }
        if(pre->next == NULL) return NULL;
        return pre->next;
    }
};