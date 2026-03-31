class Node {
public:
    int value;
    int key;
    Node* left;
    Node* right;

    Node() {
        value = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class LRUCache {
/*
    Hashmap stores the key and pointer to respective node
    this node contains value, left and right pointers

    create a doubly linked list so we can adda nd insert elements easily
    every time we get or put an element we need to remove it from the list and 
    add it back to the top
    we need a left pointer that points to the start of the list
    if we 'get' the first node, the left now points to that nodes right
    and that node that we got gets added to the top of the list
*/
public:
    LRUCache(int capacity) : m_capacity(capacity), m_size(0) {
        right = new Node();
        left = new Node();

        right->left = left;
        left->right = right;
    }
    
    void insert(Node* node, int key) {
        Node *latest = right->left;
        right->left = node;
        node->right = right;
        node->left = latest;
        node->key = key;
        latest->right = node;
        m_size++;
    }

    void remove(Node* node) {
        Node *prev = node->left;
        Node *next = node->right;
        prev->right = next;
        next->left = prev;
        m_size--;
    }

    int get(int key) {
        if (m_umap.find(key) == m_umap.end()) {
            return -1;
        }

        // remove it and insert it back so it goes to the top
        remove(m_umap[key]);
        insert(m_umap[key], key);
        return m_umap[key]->value;
    }
    
    void put(int key, int value) {
        if (m_umap.find(key) != m_umap.end()) {
            remove(m_umap[key]);
        }

        // insert with new val
        if (m_size >= m_capacity) {
            std::cout << "val: " << left->right->value << std::endl;
            Node *temp = left->right;
            remove(left->right);
            m_umap.erase(temp->key);
            delete temp;
        }
        Node *new_node = new Node(value);
        m_umap[key] = new_node;
        insert(new_node, key);
    }

private:
    Node* left;
    Node* right;
    int m_capacity;
    int m_size;
    std::unordered_map<int, Node*> m_umap;
};
