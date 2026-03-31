class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /*
            breadth first search
            keep track of global max cells and local max
            iterate over each element in the grid if it is 1 then do a bfs
            in the bfs have a queue that has a pair of integers representing i and j
            then traverse right, down left and up and if there exists a 1 add to the queue
            increment a local count -> bfs func should return the local count
            instead of a visited boolean array we can just mark the current cell (when visited) as '0'

            0,0,1,0,0,0,0,1,0,0,0,0,0
            0,0,0,0,0,0,0,1,1,1,0,0,0
            0,1,1,0,1,0,0,0,0,0,0,0,0
            0,1,0,0,1,1,0,0,1,0,1,0,0
            0,1,0,0,1,1,0,0,1,1,1,0,0
            0,0,0,0,0,0,0,0,0,0,1,0,0
            0,0,0,0,0,0,0,1,1,1,0,0,0
            0,0,0,0,0,0,0,1,1,0,0,0,0

        */
        int global_max = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    global_max = std::max(bfs(i, j, grid), global_max);
                }
            }
        }
        return global_max;
    }

    int bfs(int i, int j, vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(i, j));
        grid[i][j] = 0;
        int island_size = 0;

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;

            island_size++;
            q.pop();

            // Only add to array if it is not a 0
            if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
                q.push(std::make_pair(i, j + 1));
                grid[i][j + 1] = 0;
            }

            if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
                q.push(std::make_pair(i + 1, j));
                grid[i + 1][j] = 0;
            }

            if (j > 0 && grid[i][j - 1] == 1) {
                q.push(std::make_pair(i, j - 1));
                grid[i][j - 1] = 0;
            }

            if (i > 0 && grid[i - 1][j] == 1) {
                q.push(std::make_pair(i - 1, j));
                grid[i - 1][j] = 0;
            }
        }
        return island_size;
    }
};
