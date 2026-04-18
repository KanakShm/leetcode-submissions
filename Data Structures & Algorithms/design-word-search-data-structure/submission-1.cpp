class Node {
    public: 
    std::unordered_map<char, Node*> children;
    bool isWord = false;

    Node() {}

    ~Node() {}
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        /*
            hashmap <char, node>
            adding word, iterate through word and add to character's hashmap
            . a b
            a b
            b p c
            c d

            . -> go through entire array of neighbours
            else go through only that element
        */
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); ++i) {
            if (curr->children.find(word[i]) == curr->children.end()) {
                curr->children[word[i]] = new Node();
            }

            curr = curr->children[word[i]];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        /*
            pick the word, recurse to the next
            if it is a . iterate through each letter of alphabet and recurse
        */
        return dfs(word, root, 0);
    }

    bool dfs(std::string& word, Node* root, int i) {
        if (i == word.size()) return root->isWord;

        if (word[i] == '.') {
            for (auto iter = root->children.begin(); iter != root->children.end(); ++iter) {
                if (dfs(word, iter->second, i + 1)) return true;
            }
        }

        if (root->children.find(word[i]) == root->children.end()) {
            return false;
        }

        return dfs(word, root->children[word[i]], i + 1);
    }
};
