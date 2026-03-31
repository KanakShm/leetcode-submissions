#include <array>

class Solution {
public:
    std::vector<std::vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /*
            breadth first search each cell containing 1 and not visited
            keep track of largest area
        */

        int max = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) {
                    max = std::max(max, bfs(grid, i, j));
                }
            }
        }
        return max;
    }

    int bfs(std::vector<std::vector<int>>& grid, int i, int j) {
        std::queue<std::array<int, 2>> q;
        q.push(std::array<int, 2>{j, i});
        grid[i][j] = 0;
        int res = 1;
        while (!q.empty()) {
            std::array<int, 2> top = q.front();
            q.pop();

            // Push left right up and down
            for (int k = 0; k < dir.size(); ++k) {
                int row = top[0] + dir[k][0];
                int col = top[1] + dir[k][1];
                
                if (row >= 0 && col >= 0 && 
                    row < grid[0].size() && col < grid.size() && grid[col][row] != 0) {
                    q.push(std::array<int, 2>{row, col});
                    grid[col][row] = 0;
                    res++;
                }
            }
        }
        return res;
    }
};
