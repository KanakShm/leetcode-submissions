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
    ListNode* getGroupEnd(ListNode* curr_group, int k) {
        while (curr_group && k > 1) {
            curr_group = curr_group->next;
            k--;
        }
        return curr_group;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*
            iterate k nodes to the end of current group
            reverse current pointer until we hit k->next
            current head should point to k->next
            store prev_group end
            prev_group end = prev
        */
        ListNode* dummy = new ListNode(0, head);
        ListNode* group_prev = dummy;

        ListNode* group_start;
        while (true) {
            ListNode *group_start = group_prev->next;
            ListNode* group_end = getGroupEnd(group_start, k);
            if (!group_end) break;

            ListNode* group_next = group_end->next;
            ListNode* curr = group_start, *prev = group_next;
            while (curr && curr != group_next) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            group_prev->next = group_end;
            group_prev = group_start;
        }
        return dummy->next;
    }
};
