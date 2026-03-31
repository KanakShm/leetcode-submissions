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
            Reverse both linked list
            Traverse them and add to total of each
            add totals together
            use mod operator to get each digit push to vector
            convert vector to linked list
        */
        ListNode *head1 = l1, *prev1 = nullptr, *next;
        int size1 = 0;
        while (head1 != nullptr) {
            next = head1->next;
            head1->next = prev1;
            prev1 = head1;
            head1 = next;
            size1++;
        }

        ListNode *head2 = l2, *prev2 = nullptr;
        int size2 = 0;
        while (head2 != nullptr) {
            next = head2->next;
            head2->next = prev2;
            prev2 = head2;
            head2 = next;
            size2++;
        }

        int res1 = 0;
        int res2 = 0;
        int multiplier1 = std::pow(10, size1 - 1);
        int multiplier2 = std::pow(10, size2 - 1);
    
        while (prev1 != nullptr || prev2 != nullptr) {
            if (prev1 != nullptr) {
                res1 += prev1->val * multiplier1;
                prev1 = prev1->next;
                multiplier1 /= 10;
            }
            
            if (prev2 != nullptr) {
                res2 += prev2->val * multiplier2;
                prev2 = prev2->next;
                multiplier2 /= 10;
            }
            std::cout << res1 << " " << res2 << std::endl;
        }

        int total = res1 + res2;
        std::vector<int> nums;
        while (total != 0 || size1 > 0 || size2 > 0) {
            nums.push_back(total % 10);
            total = total / 10;
            size1--;
            size2--;
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
