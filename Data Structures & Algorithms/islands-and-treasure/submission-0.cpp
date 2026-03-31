class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        /*
            start at a 0
            breadth first search outwards
            only append to the queue if the node is not -1 or 0
            search right, down, left and right
            if the next node is not -1, then replace it with the current node 
            value + 1
            only replace the value of the node if curr + 1 is less than the value in it currently
                do this check before appending to the queue
        */
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    bfs(grid, i, j);
                }
            }
        }
    }

    void bfs(vector<vector<int>>& grid, int i, int j) {
        std::queue<std::pair<int, int>> q;
        std::unordered_map<int, int> umap;
        q.push(std::make_pair(i, j));

        while (!q.empty()) {
            std::pair<int, int> node = q.front();
            q.pop();

            // Get and update right, down, left, right
            int right = node.first * grid[0].size() + node.second + 1;
            int down = (node.first + 1) * grid[0].size() + node.second;
            int left = node.first * grid[0].size() + node.second - 1;
            int up = (node.first - 1) * grid[0].size() + node.second;

            if (node.first + 1 < grid.size() && grid[node.first + 1][node.second] != -1 && umap.find(down) == umap.end()) {
                grid[node.first + 1][node.second] = std::min(grid[node.first][node.second] + 1, grid[node.first + 1][node.second]);
                q.push(std::make_pair(node.first + 1, node.second));
                umap[down]++;
            }
            if (node.second + 1 < grid[0].size() && grid[node.first][node.second + 1] != -1 && umap.find(right) == umap.end()) {
                grid[node.first][node.second + 1] = std::min(grid[node.first][node.second] + 1, grid[node.first][node.second + 1]);
                q.push(std::make_pair(node.first, node.second + 1));
                umap[right]++;
            }
            if (node.first - 1 >= 0 && grid[node.first - 1][node.second] != -1 && umap.find(up) == umap.end()) {
                grid[node.first - 1][node.second] = std::min(grid[node.first][node.second] + 1, grid[node.first - 1][node.second]);
                q.push(std::make_pair(node.first - 1, node.second));
                umap[up]++;
            }
            if (node.second - 1 >= 0 && grid[node.first][node.second - 1] != -1 && umap.find(left) == umap.end()) {
                grid[node.first][node.second - 1] = std::min(grid[node.first][node.second] + 1, grid[node.first][node.second - 1]);
                q.push(std::make_pair(node.first, node.second - 1));
                umap[left]++;
            }
        }
    }
};
