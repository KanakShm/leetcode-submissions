/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        /*
            traverse to the start of left
            prev curr
            save before the start node so we can prev-start->next prev

            1 2 3 4 5 6 7 8 9
              s     c n
                n.n = c
            
            start.n.n = n
              2 5 4 3 6

            1 2 3 4 5
        */
        if (head.next == null) return head; 
        
        ListNode dummy = new ListNode(0, head);
        ListNode start = dummy;

        ListNode curr = head;
        ListNode next = head.next;

        for (int i = 1; i < left; ++i) {
            start = curr;
            curr = curr.next;
            next = next.next;
        }

        while (next != null && right - left > 0) {
            ListNode temp = next.next;
            next.next = curr;
            curr = next;
            next = temp;
            right--;
        }

        ListNode temp = start.next;
        start.next = curr;
        temp.next = next;

        return dummy.next;
    }
}