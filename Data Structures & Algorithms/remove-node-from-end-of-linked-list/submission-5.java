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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        /*
            1 2 3 4 5 6 7 8
        */

        int size = 0;
        ListNode curr = head;
        while (curr != null) {
            size++;
            curr = curr.next;
        }

        if (size == 1) {
            return null;
        }

        curr = head;
        ListNode prev = null;
        int idx = size - n;
        while (curr != null && idx > 0) {
            prev = curr;
            curr = curr.next;
            idx--;
        }

        if (prev == null) {
            return curr.next;
        }

        if (curr != null && curr.next != null) {
            prev.next = curr.next;
            return head;
        }

        prev.next = null;
        return head;

    }
}
