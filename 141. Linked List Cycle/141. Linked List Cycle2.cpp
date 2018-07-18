//遍历链表的同时，让前一个节点的next指向head（或者是任意一个指定的内存），
//在后续的遍历中，如果有节点的当前next指向了head，则说明有环。
//破坏链表，达到最快
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode p = head;
        while(p!=null){
            ListNode aft = p.next;
            if(aft==head) return true;
            p.next=head;
            p=aft;
        }
        return false;
    }
}