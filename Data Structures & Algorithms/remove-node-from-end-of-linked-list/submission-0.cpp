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
            Iterate through the list and get length
            iterate length - n + 1 times
            get rid of that element
        */
        int length = 0;
        ListNode *curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        ListNode *prev = nullptr, *remove = head;
        for (int i = 0; i < length - n; ++i) {
            prev = remove;
            remove = remove->next;
        }
        if (!prev) {
            return remove->next;
        }
        prev->next = remove->next;
        return head;
    }
};
