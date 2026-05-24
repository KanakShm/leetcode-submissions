class Node {
    public:
    Node(int val) : value(val) {}
    Node(int val, int key) : value(val), key(key) {}

    Node* prev = nullptr;
    Node* next = nullptr;
    int value;
    int key;
};

class LRUCache {
public:
    Node* left;
    Node* right;
    
    int size;
    int max_size;
    std::unordered_map<int, Node*> cache;
    LRUCache(int capacity) {
        /*
            Linked list with left and right
            get gets the key and detaches from linked list and 
            appends to the end before right
            put updates the key and inserts into the list before right
            if maximum exceeds then pop from left
        */
        cache.clear();
        left = new Node(0);
        right = new Node(0);

        left->next = right;
        right->prev = left;

        size = 0;
        max_size = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = right->prev;
        node->next = right;
        right->prev->next = node;
        right->prev = node;

        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // update the key and attach to the end
            Node* node = cache[key];
            node->value = value;

            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = right->prev;
            node->next = right;
            right->prev->next = node;
            right->prev = node;
        } else {
            // create a new node and attach to the end
            Node* node = new Node(value, key);
            node->prev = right->prev;
            right->prev->next = node;
            node->next = right;
            right->prev = node;

            cache[key] = node;
            size++;
        }

        if (size > max_size) {
            // remove the lru
            Node* lru = left->next;
            left->next = lru->next;
            lru->next->prev = left;

            cache.erase(lru->key);
            size--;
        }
    }
};
