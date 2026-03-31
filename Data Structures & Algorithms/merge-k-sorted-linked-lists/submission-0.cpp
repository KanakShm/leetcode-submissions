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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            merge in first two sorted linked list
            keep merging first two linked list until array size is 1
            return the first element

            to merge two sorted linked lists:
            1->1->2->4
            1->1->2->3->5
            1->1->2->3->4
            1->1->2->3->4->5
        */
        std::cout << lists.size() << std::endl;
        if (lists.empty()) {
            ListNode *empty = new ListNode();
            return nullptr;
        }
        while (lists.size() > 1) {
            ListNode dummy(0);
            ListNode* curr = &dummy;

            ListNode *list1 = lists[0];
            ListNode *list2 = lists[1];
            
            while (list1 && list2) {
                if (list1->val < list2->val) {
                    curr->next = list1;
                    list1 = list1->next;
                } else {
                    curr->next = list2;
                    list2 = list2->next;
                }
                curr = curr->next;
            }

            if (list2) {
                curr->next = list2;
            }

            if (list1) {
                curr->next = list1;
            }
            lists[0] = dummy.next;
            lists.erase(lists.begin() + 1);
        }
        return lists[0];
    }
};
