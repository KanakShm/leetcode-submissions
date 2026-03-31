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
            keep track of one before the range and one after
            reverse the range
            keep one after as "prev"
            once we finish reversing, the curr node will be pointing to the start of the reversed
            list
            one-before->next = curr;

            1 2 3 4 5
            1 4 3 2 5
        */

        ListNode dummy(0);
        ListNode* start = &dummy;
        start->next = head;

        ListNode* before = start;
        for (int i = 1; i < left; ++i) {
            before = before->next;
        }

        ListNode* after = head->next;
        for (int i = 1; i < right; ++i) {
            after = after->next;
        }

        ListNode* curr = before->next;
        ListNode* prev = after;
        while (curr != after) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        before->next = prev;
        return dummy.next;
    }   
};