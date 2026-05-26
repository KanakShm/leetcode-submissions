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
            initialise start as dummy node
            Traverse to left
            reverse from left to right
                s e
                        c n
            1 2 3 4 5 6 7 8 9 
            1 2 3 7 6 5 4 8 9

            curr->next = prev
            iterate current and prev to the next
            start->next = prev
            end->next = next
        */

        ListNode dummy(0);
        dummy.next = head;

        ListNode* start = &dummy;
        ListNode* curr = head;
        ListNode* next = curr->next;
        int count = 1;
        while (next && count < left) {
            start = curr;
            curr = curr->next;
            next = next->next;
            count++;
        }

        ListNode* end = curr;
        while (next && count < right) {
            ListNode* temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
            count++;
        }

        start->next = curr;
        end->next = next;

        return dummy.next;
    }
};