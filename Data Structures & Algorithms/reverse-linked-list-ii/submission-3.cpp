/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*
            iterate to the start
            have a prev pointer that starts at dummy node
            d 1 2 3 4 5
            d -> 1
            2 -> 1
            p c n

            do this loop for right - left + 1 iterations
            save the next's next
            next next = curr
            curr next = prev
            next = temp

            once we reverse, curr will point to right + 1
            save where the start is -> its next is now curr
        */

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
            curr = curr->next;
        }

        ListNode* start = curr;
        ListNode* next = curr->next;
        int count = right - left + 1;
        while (next && count > 1) {
           ListNode* temp = next->next;
           next->next = curr;
           curr = next;
           next = temp;
           count--;
        }

        prev->next = curr;
        start->next = next;

        return dummy.next;
    }
};