class Solution {
public:
    std::vector<std::vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        /*
            Backtracking:
            Go through each node of the matrix and dfs in all
            four directions if that direction is greater

            Dynamic Programming:
            If a cell has already been visited before return that
            solution

            If we hit a base case where there are no more cells to 
            traverse save a running number into dp array.

            Mark nodes visited
        */

        int res = 0;
        std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                res = std::max(dfs(matrix, i, j, dp), res);
            }
        }

        return res;
    }

    int dfs(std::vector<std::vector<int>>& matrix, int i, int j, 
            std::vector<std::vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int max_path_size = 1;
        for (int k = 0; k < dir.size(); ++k) {
            int row = i + dir[k][0];
            int col = j + dir[k][1];

            if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size() &&
                matrix[row][col] > matrix[i][j]) {
                    int path_size = 1 + dfs(matrix, row, col, dp);
                    max_path_size = std::max(max_path_size, path_size);
                }
        }

        dp[i][j] = max_path_size;
        return max_path_size;
    }
};
