class Solution {
public:
    std::unordered_map<int, int> rc_umap;
    std::unordered_map<int, int> pos_diag_umap;
    std::unordered_map<int, int> neg_diag_umap;
    vector<vector<string>> solveNQueens(int n) {
        /*
            initialise the board with no queens
            idea is to iterate through the columns and place a queen if valid
            once a queen is placed, we move on to the next row
            base case is if we have completed all the rows
            we can only hit this base case if we put a queen in the final row
            so if we do a continue and exit the for loop we will exit the backtrack
                and then we will need to undo that universe by removing the queen that got us there
                in the first place
        */
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> board(n, std::string(n,'.'));
        backtrack(0, n, board, res);
        return res;
    }

    inline void backtrack(int row, int n, std::vector<std::string>& board, 
                          std::vector<std::vector<std::string>>& res) 
    {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // If there is a queen attacking the current col then dont do anything
            if (rc_umap[col] || pos_diag_umap[col - row] || neg_diag_umap[col + row]) {
                continue;
            }

            // If there are no queens attacking the current col
            board[row][col] = 'Q';
            rc_umap[col]++;
            pos_diag_umap[col - row]++;
            neg_diag_umap[col + row]++;

            // Backtrack to the next row
            backtrack(row + 1, n, board, res);

            // Exit condition where we return from backtrack
            // Either we successfully reached row = n and pushed to res
            // or we need to delete the queens we added that was causing problems
            board[row][col] = '.';
            rc_umap.erase(col);
            pos_diag_umap.erase(col - row);
            neg_diag_umap.erase(col + row);
        }
    }
};
