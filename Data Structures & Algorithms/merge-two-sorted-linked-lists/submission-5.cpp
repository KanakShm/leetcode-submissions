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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       /*
            iterate through both at once
            if bottom < top->next
            top->next = bottom and stitch the list
            bottom->next is previous top->next
       */

        ListNode dummy(0);
        ListNode* head = &dummy;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                ListNode* node = new ListNode(curr1->val);
                head->next = node;
                curr1 = curr1->next;
            } else {
                ListNode* node = new ListNode(curr2->val);
                head->next = node;
                curr2 = curr2->next;
            }
            head = head->next;
        }

        if (curr1) {
            head->next = curr1;
        }

        if (curr2) {
            head->next = curr2;
        }

        return dummy.next;
    }
};
