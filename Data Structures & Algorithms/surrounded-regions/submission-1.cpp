class Solution {
public:
    int dirs[4][2] = {{0,1}, {1,0}, {0, -1}, {-1,0}};
    void solve(vector<vector<char>>& board) {
        /*
            Any 'O' that is connected to the edge cannot be surrounded
            and any 'O' that is connected to that cannot either

            Traverse only the edge nodes, and dfs on them, marking each with a 'T'

            Then traverse matrix normally and mark each O with X and each T with O

            "X","O","X","X"
            "O","X","O","X"
            "X","O","X","O"
            "O","X","O","X"
        */

        for (int i = 0; i < board[0].size(); ++i) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[board.size() - 1][i] == 'O') {
                dfs(board, board.size() - 1, i);
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][board[0].size() - 1] == 'O') {
                dfs(board, i, board[0].size() - 1);
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }

    void dfs(std::vector<std::vector<char>>& board, int row, int col) {
        if (board[row][col] == 'X') return;
        if (board[row][col] == 'T') return;

        if (board[row][col] == 'O') board[row][col] = 'T';

        for (int i = 0; i < 4; ++i) {
            int next_row = row + dirs[i][0];
            int next_col = col + dirs[i][1];

            if (next_row <= board.size() - 1 && next_row >= 0 &&
                next_col <= board[0].size() - 1 && next_col >= 0) {
                   dfs(board, next_row, next_col);
            }
        }
    }
};
