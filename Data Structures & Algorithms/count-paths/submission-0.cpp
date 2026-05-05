class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
            Dynamic programming
            Unique paths from i = paths from [i + 1][j] + [i][j + 1]
            start from the end put the up and left neighbours in a queue if they
            arent already in it and update the current using the subproblems from 
            right and down
        */

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;

        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        q.push({m - 1, n - 1});
        while (!q.empty()) {
            std::pair<int, int> cell = q.front();
            int row = cell.first;
            int col = cell.second;
            q.pop();

            // DP bottom and right cell
            int right = 0;
            int left = 0;
            if (row + 1 < m) right = dp[row + 1][col];
            if (col + 1 < n) left = dp[row][col + 1];

            dp[row][col] += right + left;

            // Push up and left
            if (row - 1 >= 0 && !visited[row - 1][col]) {
                q.push({row - 1, col});
                visited[row - 1][col] = true;
            }

            if (col - 1 >= 0 && !visited[row][col - 1]) {
                q.push({row, col - 1});
                visited[row][col - 1] = true;
            }
        }

        return dp[0][0];
    }
};
