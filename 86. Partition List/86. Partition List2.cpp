链接：https://www.nowcoder.com/questionTerminal/1dc1036be38f45f19000e48abe00b12f
来源：牛客网

题意：给定一个单链表和一个x，把链表中小于x的放到前面，大于等于x的放到后面，每部分元素的原始相对位置不变。
思路：新建两个节点preHead1与preHead2，分别为指向两个链表的头结点。
把节点值小于x的节点链接到链表1上，节点值大等于x的节点链接到链表2上。
最后把两个链表相连即可
public ListNode partition(ListNode head, int x) {
        //preHead1与preHead2分别为两个链表头结点的前移节点（一个链表的节点值小于x，另一个大于等于x）
        ListNode preHead1 = new ListNode(0), preHead2 = new ListNode(0);
        ListNode cur1 = preHead1, cur2 = preHead2;
        while (head != null) {
            if (head.val < x) {
                cur1.next = head;
                cur1 = cur1.next;
            } else {
                cur2.next = head;
                cur2 = cur2.next;
            }
            head = head.next;
        }
        cur1.next = preHead2.next;
        cur2.next = null;
        return preHead1.next;
 
    }