class Node {
public:
    Node(char letter) : letter(letter){}

    char letter;
    bool is_word = false;
    std::unordered_map<char, Node*> next_letter;
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        /*
            word dictionary has access to root node .
            each node has a hashmap of letter, node
            add word adds the word until the end of the word and marks that last node as a word
            search, if we see that there is a ., then we have to move idx++ and search all next letters
            in the node hashmap
                recursive
        */
        root = new Node('.');
    }   
    
    void addWord(string word) {
        Node* curr = root;
        int i = 0;
        while (i < word.size() && curr->next_letter.find(word[i]) != curr->next_letter.end()) {
            curr = curr->next_letter[word[i]];
            i++;
        }

        while (i < word.size()) {
            curr->next_letter[word[i]] = new Node(word[i]);
            curr = curr->next_letter[word[i]];
            i++;
        }

        curr->is_word = true;
    }

    bool dfs(std::string word, int i, Node* curr) {
        if (i == word.size()) return curr->is_word;

        if (word[i] == '.') {
            for (auto iter = curr->next_letter.begin(); iter != curr->next_letter.end(); ++iter) {
                if (dfs(word, i + 1, iter->second)) return true;
            }
        }

        if (curr->next_letter.find(word[i]) != curr->next_letter.end()) {
            return dfs(word, i + 1, curr->next_letter[word[i]]);
        }

        return false;
    }
    
    bool search(string word) {
        /*
            dfs till we find the end of the word
            if we see . then recurse i + 1
            base case when i == word size
        */
        int i = 0;
        return dfs(word, i, root);
    }   
};
