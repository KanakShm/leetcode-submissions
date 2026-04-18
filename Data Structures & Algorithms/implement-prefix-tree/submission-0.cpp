class Node {
public:
    Node(char c) : character(c) {}

    char character;
    bool is_word = false;
    std::unordered_map<char, Node*> next_character;
};

class PrefixTree {
public:
    /*  
        tree with current word (string) and hashmap of node pointers to added words that are one more than
        current

        dog
        loop through the string starting at "", which contains the first letter to all
        inserted words, append d if it isnt already there, create a new node, recurse there
        and append e and so on

        search would recursively search the hashmap of "" for the first part of the string,
        go to that node and search for the next part and so on, only return true if we finish the word
    */

    PrefixTree() {
        root = new Node('.');
    }
    
    void insert(string word) {
        dfs_insert(word, root, 0);
    }

    // apple app
    void dfs_insert(std::string& word, Node* root, int i) {
        if (i == word.size()) {
            root->is_word = true;  
            return;  
        }

        if (root->next_character.find(word[i]) == root->next_character.end()) {
            Node* new_character = new Node((char)word[i]);
            root->next_character[word[i]] = new_character;
            dfs_insert(word, new_character, i + 1);
        } else {
            dfs_insert(word, root->next_character[word[i]], i + 1);
        }
    }
    
    bool search(string word) {
        return searchDFS(word, root, 0);
    }

    bool searchDFS(std::string& word, Node* root, int i) {
        if (i == word.size()) return root->is_word;

        // we loop through each character and see if it exists in the current node's hashmap
        // app .apple
        if (root->next_character.find(word[i]) == root->next_character.end()) {
            return false;
        }

        return searchDFS(word, root->next_character[word[i]], i + 1);
    }
    
    bool startsWith(string prefix) {
        return startsWithDFS(prefix, root, 0);
    }

    bool startsWithDFS(std::string& word, Node* root, int i) {
        if (i == word.size()) return true;
        if (root->next_character.find(word[i]) == root->next_character.end()) {
            return false;
        }

        return startsWithDFS(word, root->next_character[word[i]], i + 1);
    }

    Node* root;
};
