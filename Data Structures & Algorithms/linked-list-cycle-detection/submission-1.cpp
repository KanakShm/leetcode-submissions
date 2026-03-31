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
    bool hasCycle(ListNode* head) {
        /*
            Have two pointers a fast and a slow. Increment fast by 2 and slow by 1
            If at any time fast = slow then there exists a cycle
        */
        ListNode *fast = head, *slow = head;
        while (fast) {
            if (fast->next == nullptr) break;
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        return false;
    }
};
