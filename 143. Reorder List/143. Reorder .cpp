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
        ListNode* sim, *dou, *temp;
        
        if(head->next && head->next->next) {
            sim = head;
            dou = head->next;
        }
        else return;
        temp = head->next;
        while(sim->next && sim->next->next) {
            if(sim->next && sim->next->next) sim = sim->next = sim->next->next;
            if(dou->next && dou->next->next) dou = dou->next = dou->next->next;
        }
        sim->next = NULL;
        sim = head;
        dou = temp;
        temp = NULL;
        cout<<dou->val<<endl;
        ListNode* pre;
        while(dou) {
            if(dou->next) pre = dou->next;
            else {
                dou->next = temp;
                break;
            }
            dou->next = temp;
            temp = dou;
            dou = pre;  
        }
        while(sim) {cout<<sim->val<<endl; sim = sim->next;}
        while(dou) {cout<<dou->val<<endl; dou = dou->next;}
        temp = head;
        while()
    }
};
//看错题了 这是奇偶排序