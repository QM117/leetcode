/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *copy, *p, *phead;
        if(head == NULL) return NULL;
        for(p = head;p;p=p->next) {
            copy = new RandomListNode(p->label);
            copy->next = p->next;
            p = p->next = copy;
        }
        for(p = head;p;p=copy->next) {
            copy = p->next;
            if(p->random) copy->random = p->random->next;
            else copy->random = NULL;
        }
        phead = head;
        while(phead) {
            cout<<phead->label<<endl;
            phead = phead->next;
        }
        
        for(p=head,head=copy=p->next;p;){
            p = p->next = copy->next;
            copy = copy->next = (p?p->next:NULL);
        }
        return head;
    }
};
//别人的算法 主要的是 copy->random = p->random->next; 这里是因为p->random只是p的链要链到在p之后的copy的链 以后如果要新建一个节点用new