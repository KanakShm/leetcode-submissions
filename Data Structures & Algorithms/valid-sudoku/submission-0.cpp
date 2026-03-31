class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
            Go through the rows and check for duplicates
            Go through the coloumns and check for duplicates
            Go through the grid cells and check for duplicates

            Hashmap that resets every iteration key = number, value = occurrance
        */

        std::unordered_map<char, int> umap;
        
        // Iterate through the rows
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (umap.find(board[i][j]) == umap.end()) {
                    umap[board[i][j]]++;
                } else {
                    std::cout << "row" << std::endl;
                    return false;
                }
            }
            umap.clear();
        }
        umap.clear();

        // Iterate through the columns
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[j][i] == '.') {
                    continue;
                }

                if (umap.find(board[j][i]) == umap.end()) {
                    umap[board[j][i]]++;
                } else {
                    std::cout << "col" << std::endl;
                    return false;
                }
            }
            umap.clear();
        }
        umap.clear();

        // Iterate through the grids
        for (int start_row = 0; start_row < 9; start_row += 3) {
            for (int start_col = 0; start_col < 9; start_col += 3) {
                for (int i = start_row; i < start_row + 3; ++i) {
                    for (int j = start_col; j < start_col + 3; ++j) {
                        if (board[i][j] == '.') {
                            continue;
                        }

                        if (umap.find(board[i][j]) == umap.end()) {
                            umap[board[i][j]]++;
                        } else {
                            std::cout << "grid" << std::endl;

                            return false;
                        }
                    }
                }
                umap.clear();
            }
        }

        return true;
    }
};
