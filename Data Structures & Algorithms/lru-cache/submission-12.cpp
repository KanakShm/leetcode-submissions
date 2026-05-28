class Node {
public:
    Node(int val, int key) : value(val), key(key){}

    Node* next = nullptr;
    Node* prev = nullptr;
    int value;
    int key;
};

class LRUCache {
public:
    std::unordered_map<int, Node*> cache;
    Node* start;
    Node* end;
    int max_size;
    int curr_size;
    LRUCache(int capacity) {
        /*  
            Need to track the start for order 1 removal
            Always append to the end
            doubly linked list
            hashmap <int, Node*>

            get updates the node to the end
            put adds a new node to the end and removes a node from the start
            if needed
        */
        
        start = new Node(0,0);
        end = new Node(0,0);
        start->next = end;
        end->prev = start;
        max_size = capacity;
        curr_size = 0;
    }

    // Only responsible for insertion
    void insert(Node* node) {
        Node* temp = end->prev;
        end->prev = node;
        node->next = end;
        temp->next = node;
        node->prev = temp;
        curr_size++;
    }

    // Only responsible for deletion
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        curr_size--;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        remove(cache[key]);
        insert(cache[key]);
        return cache[key]->value;
    }

    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            cache[key] = new Node(value, key);
            insert(cache[key]);
        } else {
            remove(cache[key]);
            cache[key]->value = value;
            insert(cache[key]);
        }

        if (curr_size > max_size) {
            Node* temp = start->next;
            remove(start->next);
            cache.erase(temp->key);
        }
    }
};
