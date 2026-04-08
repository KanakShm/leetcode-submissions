#include <array>
class Solution {
public:
    std::array<std::array<int, 2>, 4> dir = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        /*  
            modify the input array
            add the index to the queue
            closest distance from a treasure chest to each land cell
            start at the treasure chest and bfs outwards
                if the next island is a land cell add it to the queue
                update the output to be the 1 plus the current number
                    the min of this compared to whatever it is right now
        */
        std::queue<std::vector<int>> q;
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        bfs(grid, q, visited);
    }

    void bfs(std::vector<std::vector<int>>& grid, std::queue<std::vector<int>> q, std::vector<std::vector<bool>>& visited) {
        while (!q.empty()) {
            std::vector<int> cell = q.front();
            q.pop();
            visited[cell[0]][cell[1]] = true;

            for (int i = 0; i < dir.size(); ++i) {
                int new_row = cell[0] + dir[i][0];
                int new_col = cell[1] + dir[i][1];

                if (new_row >= 0 && new_row < grid.size() &&
                    new_col >= 0 && new_col < grid[0].size() &&
                    grid[new_row][new_col] != -1 && !visited[new_row][new_col]) {
                        grid[new_row][new_col] = std::min(grid[new_row][new_col], grid[cell[0]][cell[1]] + 1);
                        q.push({new_row, new_col});
                    }
                
            }
        }
    }
};
