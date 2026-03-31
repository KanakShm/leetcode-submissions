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
            We loop through the linked list
            Append to a hashmap <current, copy>
            loop through the linked list again and for every node we do a lookup to our copy
            and append the address of that
        */

        std::unordered_map<Node*, Node*> copy;
        copy[nullptr] = nullptr;
        Node* curr = head;

        // Here we are creating a copy of the current node and then saving its pointer to our hashmap
        while (curr) {
            Node *new_node = new Node(curr->val);
            copy[curr] = new_node;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            Node* node_copy = copy[curr];
            node_copy->next = copy[curr->next];
            node_copy->random = copy[curr->random];
            curr = curr->next;
        }
        return copy[head];
    }
};
