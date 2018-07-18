链接：https://www.nowcoder.com/questionTerminal/650474f313294468a4ded3ce0f7898b9
来源：牛客网

//快慢指针能相遇说明有环！
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null)
            return false;
        ListNode fast=head;
        ListNode slow=head;
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            if(fast==slow)
                return true;
        }
        return false; 
    }
}