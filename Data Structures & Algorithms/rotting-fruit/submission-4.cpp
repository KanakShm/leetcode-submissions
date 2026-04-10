class Solution {
public:
    std::vector<std::vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        /*
            multiple rotten fruits we will do a multi source BFS
            append indices of all rotten fruits to a queue
            traverse all four directions
            one minute is one whole pop of queue
        */

        std::queue<std::vector<int>> q;
        int fruits = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] != 0) {
                    fruits++;
                }
            }
        }

        int time = std::max(bfs(grid, q, fruits), 0);
        return fruits > 0 ? -1 : time;

    }

    int bfs(std::vector<std::vector<int>>& grid, std::queue<std::vector<int>>& q, int& fruits) {
        int time = -1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                std::vector<int> cell = q.front();
                q.pop();

                // make all other fruits in all other directions rotten as well
                for (int j = 0; j < dir.size(); ++j) {
                    int next_row = cell[0] + dir[j][0];
                    int next_col = cell[1] + dir[j][1];

                    if (next_row >= 0 && next_row < grid.size() &&
                        next_col >= 0 && next_col < grid[0].size() &&
                        grid[next_row][next_col] == 1) {
                            fruits--;
                            grid[next_row][next_col] = 2;
                            q.push({next_row, next_col});
                        }
                }
            }
            time++;
        }

        return time;
    }
};
