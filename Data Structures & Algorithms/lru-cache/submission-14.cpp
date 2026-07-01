class Node {
public:
    Node(int val, int k) : next(nullptr), prev(nullptr), value(val), key(k){}
    ~Node() {}
    Node* next;
    Node* prev;
    int value;
    int key;
};

class LRUCache {
public:
    Node* start;
    Node* end;

    std::unordered_map<int, Node*> cache;
    int max_size;
    int curr_size;
    LRUCache(int capacity) {
        /*
            pointers to start and end of the linked list
            helper function to remove node and append to the end
            helper function to remove lru

            hashmap<key, node>
            node: value
            
            get, calls append to append to mru
            return node value

            put updates the value and calls append
            if value doesnt exist
                capacity exceeded -> remove
                append to the end
        */
        start = new Node(0, 0);
        end = new Node(0, 0);

        start->next = end;
        end->prev = start;

        max_size = capacity;
        curr_size = 0;
    }
    
    void push(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        Node* temp = end->prev;
        end->prev = node;
        node->next = end;
        node->prev = temp;
        temp->next = node;
    }

    void pop() {
        Node* lru = start->next;
        if (!lru->next) return;

        start->next = lru->next;
        lru->next->prev = start;
        cache.erase(lru->key);
        delete lru;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            push(node);
            return node->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->value = value;
            push(cache[key]);
        } else {

            if (curr_size >= max_size) {
                pop();
            }

            Node* temp = end->prev;
            Node* new_node = new Node(value, key);
            cache[key] = new_node;
            new_node->prev = temp;
            temp->next = new_node;
            end->prev = new_node;
            new_node->next = end;
            curr_size++;
        }
    }
};
