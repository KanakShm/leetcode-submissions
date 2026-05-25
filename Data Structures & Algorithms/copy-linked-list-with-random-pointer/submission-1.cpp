/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        hashmap linking old to new
        go through the linked list and if the old node doesnt
        exist in the current hashmap, add it and link it to a new
        copy of that node. dont do anything to the random pointer

        loop through list again and append the random pointer to the new
        node
        */

        std::unordered_map<Node*, Node*> old_to_new;
        Node* temp = head;
        while (temp) {
            old_to_new[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp) {
            old_to_new[temp]->next = old_to_new[temp->next];
            old_to_new[temp]->random = old_to_new[temp->random];
            temp = temp->next;
        }

        return old_to_new[head];
    }
};
