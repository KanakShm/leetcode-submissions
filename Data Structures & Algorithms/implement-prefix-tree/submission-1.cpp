class Node {
public:
    Node(char letter) : letter(letter), is_word{false} {}
    char letter;
    bool is_word;
    std::unordered_map<char, Node*> next_letter;
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        /*
            hashmap<Node*, hashset<Node*>
            prefix tree contains the root node .
            a: b c
            b: c
            c: d
            b:
            c:

            start the tree with root node .
            inserting recursively
            search recursively, if we are at the end and boolean word is true
            search recursively, return true if we reach the end of the prefix
        */
        root = new Node('.');
    }
    
    void insert(string word) {
        int idx = 0;
        Node* curr = root;
        while (idx < word.size() && curr->next_letter.find(word[idx]) != curr->next_letter.end()) {
            curr = curr->next_letter[word[idx]];
            idx++;
        }

        while (idx < word.size()) {
            curr->next_letter[word[idx]] = new Node(word[idx]);
            curr = curr->next_letter[word[idx]];
            idx++;
        }

        curr->is_word = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        int idx = 0;
        while (idx < word.size() && curr->next_letter.find(word[idx]) != curr->next_letter.end()) {
            curr = curr->next_letter[word[idx]];
            idx++;
        }

        return idx == word.size() && curr->is_word;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        int idx = 0;
        while (idx < prefix.size() && curr->next_letter.find(prefix[idx]) != curr->next_letter.end()) {
            curr = curr->next_letter[prefix[idx]];
            idx++;
        }

        return idx == prefix.size();
    }
};
