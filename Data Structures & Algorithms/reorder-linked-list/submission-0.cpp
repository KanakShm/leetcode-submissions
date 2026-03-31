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
    void reorderList(ListNode* head) {
        /*
           Iterate to the second half of the linked list
           Reverse the second half of the linked list
           iterate from the beginning and middle and change the next pointers of each appropriately
           [0,1,2,3,4,5]
           [0,1,2]
           [5,4,3]
           [0,1,2,5,4,3]
           [0,5,1,4,2,3]
                  
           [0,1,2,3,4,5,6]
           [0,1,2,6,5,4,3] <- we ran out of elements in the first array. We should break the linked list into two
           [0,6,1,5,2,4,3]
        */

        // Slow points to middle of list
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Break the list and reverse
        ListNode *prev = nullptr, *curr = slow->next, *next;
        slow->next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Prev points to start of list
        ListNode *list1 = head, *list2 = prev;
        ListNode *list1_next, *list2_next; 
    
        /*
            [0,1,2,3,4,5,6]

            [0,1,2]
            [6,5,4,3]
            0,6,1,5,2
        */
        while (list2) {
            list1_next = list1->next;
            list2_next = list2->next;
            list1->next = list2;
            list2->next = list1_next;
            list1 = list1_next;
            list2 = list2_next;
        }
    }
};
