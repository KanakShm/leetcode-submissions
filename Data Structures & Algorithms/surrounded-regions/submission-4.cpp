class Solution {
public:
    std::vector<std::vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        /*  
            iterate through the edges of the board and append the indices of the 0s
            to a queue
            multi-source bfs

            every cell we traverse cannot be converted to an x
            convert each cell to a T
            Mark T when you push to the queueu to avoid duplicate values of the same cell
            run through grid again and convert all O to X and all T to O
        */

        std::queue<std::vector<int>> q;
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = 'T';
                q.push({i,0});
            }
            if (board[i][board[0].size() - 1] == 'O') {
                board[i][board[0].size() - 1] = 'T';
                q.push({i,(int)board[0].size() - 1});
            }
        }

        for (int i = 0; i < board[0].size(); ++i) {
            if (board[0][i] == 'O') {
                board[0][i] = 'T';
                q.push({0,i});
            }
            if (board[board.size() - 1][i] == 'O') {
                board[board.size() - 1][i] = 'T';
                q.push({(int)board.size() - 1, i});
            }
        }

        bfs(board, q);

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void bfs(std::vector<std::vector<char>>& board, std::queue<std::vector<int>>& q) {
        while (!q.empty()) {
            std::vector<int> cell = q.front();
            q.pop();
            for (int i = 0; i < dir.size(); ++i) {
                int next_row = cell[0] + dir[i][0];
                int next_col = cell[1] + dir[i][1];

                if (next_row >= 0 && next_row < board.size() &&
                    next_col >= 0 && next_col < board[0].size() &&
                    board[next_row][next_col] == 'O') {
                        q.push({next_row, next_col});
                        board[next_row][next_col] = 'T';
                    }
            }
        }
    }
};
