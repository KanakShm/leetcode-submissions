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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
            Iterate through the linked lists and add to array by using 
            integer addition

            Keep track of a carry term
        */
        int carry = 0;
        std::vector<int> nums;
        ListNode *head1 = l1, *head2 = l2;
        while (head1 != nullptr || head2 != nullptr) {
            if (head1 != nullptr && head2 == nullptr) {
                int sum = head1->val + carry;
                if (sum >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                nums.push_back(sum % 10);
                head1 = head1->next;
            } else if (head1 == nullptr && head2 != nullptr) {
                int sum = head2->val + carry;
                if (sum >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                nums.push_back(sum % 10);
                head2 = head2->next;
            } else {
                int sum = head1->val + head2->val + carry;
                if (sum >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                nums.push_back(sum % 10);
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        if (carry) {
            nums.push_back(1);
        }

        ListNode* dummy = new ListNode();
        ListNode* dummy_head = dummy;
        for (int i = 0; i < nums.size(); ++i) {
            dummy_head->next = new ListNode(nums[i]);
            dummy_head = dummy_head->next;
        }
        return dummy->next;
    }
};
