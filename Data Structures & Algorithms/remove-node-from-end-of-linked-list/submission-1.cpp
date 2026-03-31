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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            Initialise 2 pointers with distance equal to n
            By the time fast pointer reaches the end of the list the slow pointer will
            reach the node we want to delete
            dummy node to keep track of previous element
        */
        ListNode *fast = head;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *slow = dummy;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }
};
