class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*
            only iterate the word length times before returning false or true
            iterate right, then down then left then right then up
            use a visited array so we dont visit the same letter again
            use a local/current word string that updates each backtracking call
            always push to this string and pop after each backtrack
            write functions for get up, right, down, left indices of the board
            pass in indices to backtracking function
        */
        std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                visited[i][j] = false;
            }
        }
        std::string curr_word;
        bool res = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                res |= backtrack(board, word, visited, curr_word, i, j);
            }
        }
        return res;
    }

    std::pair<int, int> getUp(const int i, const int j, const std::vector<std::vector<char>>& board)
    {   
        int new_i = i - 1;
        int new_j = j;
        if (new_i < 0) new_i = -1;
        return std::make_pair(new_i, new_j);
    }

    std::pair<int, int> getRight(const int i, const int j, const std::vector<std::vector<char>>& board)
    {   
        int new_i = i;
        int new_j = j + 1;
        if (new_j >= board[0].size()) new_j = -1;
        return std::make_pair(new_i, new_j);
    }

    std::pair<int, int> getDown(const int i, const int j, const std::vector<std::vector<char>>& board)
    {   
        int new_i = i + 1;
        int new_j = j;
        if (new_i >= board.size()) new_i = -1;
        return std::make_pair(new_i, new_j);
    }

    std::pair<int, int> getLeft(const int i, const int j, const std::vector<std::vector<char>>& board)
    {   
        int new_i = i;
        int new_j = j - 1;
        if (new_i < 0) new_j = -1;
        return std::make_pair(new_i, new_j);
    }
    
    bool backtrack(const std::vector<std::vector<char>>& board, const std::string& word, 
                         std::vector<std::vector<bool>> visited, std::string curr_word,
                         int i, int j)
    {
        if (curr_word == word) {
            return true;
        }

        if (curr_word.size() == word.size()) {
            return false;
        }
        
        // Add the curernt word and mark visited
        curr_word += board[i][j];
        visited[i][j] = true;

        // Backtrack right
        std::pair<int, int> right = getRight(i, j, board);
        bool is_right = false;
        if (curr_word == word || (right.second >= 0 && !visited[right.first][right.second])) {
            is_right = backtrack(board, word, visited, curr_word, right.first, right.second);
        }

        // Backtrack down
        std::pair<int, int> down = getDown(i, j, board);
        bool is_down = false;
        if (down.first >= 0 && !visited[down.first][down.second]) {
            is_down = backtrack(board, word, visited, curr_word, down.first, down.second);
        }

        // Backtrack left
        std::pair<int, int> left = getLeft(i, j, board);
        bool is_left = false;
        if (left.second >= 0 && !visited[left.first][left.second]) {
            is_left = backtrack(board, word, visited, curr_word, left.first, left.second);
        }

        // Backtrack up
        std::pair<int, int> up = getUp(i, j, board);
        bool is_up = false;
        if (up.first >= 0 && !visited[up.first][up.second]) {
            is_up = backtrack(board, word, visited, curr_word, up.first, up.second);
        }

        curr_word.pop_back();
        visited[i][j] = false;
        return is_up | is_down | is_left | is_right;
    }
};
