class Node {
public:
    Node() {}
    ~Node() {}

    std::unordered_map<char, Node*> neighbours;
    bool is_word = false;  
};

class Solution {
public:
    std::vector<std::vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::vector<std::string> res;
    std::unordered_set<std::string> res_contains;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /*
            trie prefix tree
            . -> hashmap of letters
            . [b,c,s]
            b [a]
            a [t,c]
            boolean true the end of a word
            generate the prefix tree
                Node class

            traverse the grid
                traverse with root
                only dfs if root's hashmap contains the current character
        */
        Node* root = new Node();
        for (int i = 0; i < words.size(); ++i) {
            std::string word = words[i];
            Node* curr = root;
            for (int j = 0; j < word.size(); ++j) {
                if (curr->neighbours.find(words[i][j]) == curr->neighbours.end()) {
                    curr->neighbours[words[i][j]] = new Node();
                }
                curr = curr->neighbours[words[i][j]];
            }
            curr->is_word = true;
        }

        std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (root->neighbours.find(board[i][j]) != root->neighbours.end()) {
                    std::string word;
                    dfs(board, i, j, root->neighbours[board[i][j]], word, visited);
                }
            }
        }
        
        return res;
    }

    void dfs(std::vector<std::vector<char>>& board, int i, int j, Node* root, std::string& word, std::vector<std::vector<bool>>& visited) {
        if (root->is_word) {
            word.push_back(board[i][j]);

            if (!res_contains.count(word)) {
                res.push_back(word);
                res_contains.insert(word);
            }

            word.pop_back();
        }

        word.push_back(board[i][j]);
        visited[i][j] = true;

        for (int k = 0; k < dir.size(); ++k) {
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];

            if (next_i >= 0 && next_i < board.size() &&
                next_j >= 0 && next_j < board[0].size() &&
                !visited[next_i][next_j] &&
                root->neighbours.find(board[next_i][next_j]) != root->neighbours.end()) {
                    dfs(board, next_i, next_j, root->neighbours[board[next_i][next_j]], word, visited);
            }
        }

        word.pop_back();
        visited[i][j] = false;
    }
};
