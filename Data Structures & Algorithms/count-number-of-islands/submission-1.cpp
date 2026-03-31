class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
            depth first search
            start at first node if it is 1 then perform dfs else move forward
            only dfs if it is a 1 and it is not visited
            mark that place as visited and grow the island right, down, left and up
            return once there is no other island adjacent to it that we can visit
            once all of the backtracking has been done, increment number of islands by 1 and traverse to the next element
            again only dfs if it is a 1 and not visited

            "1","1","0","0","1"
            "1","1","0","0","1"
            "0","0","1","0","0"
            "0","0","0","1","1"
        */
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        int islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!visited[i][j] && static_cast<int>(grid[i][j] - '0')) {
                    dfs(i, j, grid, visited);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(int i, int j, const vector<vector<char>>& grid, std::vector<std::vector<bool>>& visited) {
        // Bounds check
        if (i >= grid.size() || j >= grid[0].size()) {
            return;
        }

        // Value check
        if (visited[i][j] || static_cast<int>(grid[i][j] - '0') == 0) {
            visited[i][j] == true;
            return;
        }

        visited[i][j] = true;

        // Traverse right, down, left and right
        dfs(i, j + 1, grid, visited);
        dfs(i + 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
        dfs(i - 1, j, grid, visited);
    }
};
