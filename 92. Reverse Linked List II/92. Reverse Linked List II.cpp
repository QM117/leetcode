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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return NULL;
        if(head->next == NULL) return head;
        ListNode *phead = new ListNode(0);
        bool flag = false;
        phead->next = head;
        if(m > 1) {
            m++;
            n++;   
        } else {
            n++;
            flag =true;
        }

        while(m>2) {
            phead = phead->next;
            m--;
            n--;
        }
        ListNode *p, *temp;
        if(phead->next) p =phead->next;
        n--;
        ListNode *tail = p;
        ListNode *N = NULL;
        temp = p->next;
        while(n>1) {
            p->next = N;
            N = p;
            p=temp;
            if(temp->next) temp = temp->next;
            else temp = NULL;
            //cout<<n<<endl;
            n--;
        }
        p->next = N;
        phead->next = p;
        tail->next = temp;
        if(flag) return phead->next;
        else return head;
    }
};
//注意开头就反转的情况