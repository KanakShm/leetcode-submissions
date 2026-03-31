#include <unordered_map>
class Node {
public:
    Node() : val(0), key(0), next(nullptr), prev(nullptr) {}
    Node(int val, int key, Node* next, Node* prev) : val(val), key(key), next(next), prev(prev) {}

    int val;
    int key;
    Node* next;
    Node* prev;
};

class LRUCache {
/*
    Adding a key exceeds capacity then kick out the least recently used
        free whatver is tied to the left node
    have a left node least recently used and right most recently used
    if you put a new node you connect the right node to it
    every time you get, you tie the previous to the next of the getted node and link it
        to the right node

    Hashmap of pointers to nodes
*/

public:
    LRUCache(int capacity) : m_capacity(capacity), m_size(0) {
        // Initialise left and right nodes and connect them together
        start = new Node();
        end = new Node();

        start->next = end;
        end->prev = start;
    }
    
    int get(int key) {
        int res = -1;
        if (umap.find(key) != umap.end()) {
            res = umap[key]->val;
            Node* n = umap[key];
            Node* n_prev = n->prev;
            Node* n_next = n->next;
            n_prev->next = n_next;
            n_next->prev = n_prev;

            n->next = end;
            Node* mru = end->prev;
            mru->next = n;
            n->prev = mru;
            end->prev = n;
        }
        return res;
    }
    
    void put(int key, int value) {
        // insert into the hashmap -> first find if it exists
        // end prev is pointing to this new node
        if (umap.find(key) != umap.end()) {
            Node* temp = umap[key];
            temp->val = value;
            Node* previous = temp->prev;
            Node* next = temp->next;
            previous->next = next;
            next->prev = previous;

            temp->next = end;
            Node* prev_end = end->prev;
            prev_end->next = temp;
            end->prev = temp;
            temp->prev = prev_end;
        } else {
            Node* prev = end->prev;
            Node* new_node = new Node(value, key, nullptr, nullptr);
            prev->next = new_node;
            new_node->next = end;
            new_node->prev = prev;
            end->prev = new_node;
            umap[key] = new_node;
            m_size++;
        }

        if (m_size > m_capacity) {
            Node* node_to_remove = start->next;
            Node* new_lru = node_to_remove->next;
            new_lru->prev = start;
            start->next = new_lru;
            umap.erase(node_to_remove->key);
            delete node_to_remove;
            m_size--;
        }
    }

private:
    int m_capacity;
    int m_size;
    Node* start;
    Node* end;

    std::unordered_map<int, Node*> umap;
};
