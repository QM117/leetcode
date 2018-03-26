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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* compare = head;
        while(compare->next != NULL && compare != NULL){
            if(compare->next->val < compare->val){
                if(compare == head){
                    int x = compare->val;
                    compare->val = compare->next->val;
                    compare->next->val = x;
                    compare = compare->next;
                }
                else{
                    ListNode* temp = head;
                    while(temp != compare){
                        if(temp->val > compare->next->val){
                            ListNode* i = temp->next;
                            temp->next = compare->next;
                            compare->next = compare->next->next;
                            temp->next->next = i;
                            int x = temp->val;
                            temp->val = temp->next->val;
                            temp->next->val = x;
                            break;
                        }
                        else if(temp->next->val >= compare->next->val && temp->val < compare->next->val){
                            ListNode* i = temp->next;
                            temp->next = compare->next;
                            compare->next = compare->next->next;
                            temp->next->next = i;
                            cout<<compare->val<<" "<<endl;
                            break;
                        }
                        else temp = temp->next;
                    }
                }
            }
            else {cout<<compare->val<<endl; compare = compare->next;}
        }
        return head;
    }
};
//受罪··· 自己边界条件没考虑好 写了4个小时···