class Solution {
public:
    std::vector<std::vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        /*
            Multi source BFS
            append all 0 to a queue
            pop from the queue and look at all four directions
                if ! -1 replace the current cell with 
                min of (the value of popped cell + 1, curr cell value)
                push the current cell into the queue
                dont push visited cells
                add cell to visited array
        */

        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        std::queue<std::pair<int, int>> q;
        for (int i = 0;i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) q.push({i,j});
            }
        }

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int j = 0; j < dir.size(); ++j) {
                    int next_row = row + dir[j][0];
                    int next_col = col + dir[j][1];

                    if (next_row >= 0 && next_row < grid.size() &&
                        next_col >= 0 && next_col < grid[0].size() &&
                        !visited[next_row][next_col] && grid[next_row][next_col] != -1) {
                            grid[next_row][next_col] = std::min(grid[next_row][next_col], grid[row][col] + 1);
                            visited[next_row][next_col] = true;
                            q.push({next_row, next_col});
                        }
                }
            }
        }
    }
};
