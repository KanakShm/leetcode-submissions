class Solution {
public:
    std::vector<std::vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        /*
            Swimming takes no time so we only need to record the max
            elevation.
            Use dijkestra
        */

        int max_time = INT_MIN;
        std::unordered_set<int> visited;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> min_heap;
        min_heap.push({grid[0][0],0});

        while (!min_heap.empty()) {
            std::pair<int, int> top = min_heap.top();
            min_heap.pop();

            max_time = std::max(max_time, top.first);
            visited.insert(top.second);

            int row = top.second / grid[0].size();
            int col = top.second % grid[0].size();

            if (row == grid.size() - 1 && col == grid[0].size() - 1) break;

            for (int i = 0; i < dir.size(); ++i) {
                int next_row = row + dir[i][0];
                int next_col = col + dir[i][1];
                int next_idx = next_row * grid[0].size() + next_col;

                if (next_row >= 0 && next_row < grid.size() &&
                    next_col >= 0 && next_col < grid[0].size() &&
                    !visited.count(next_idx)) {
                        int weight = grid[next_row][next_col];
                        min_heap.push({weight, next_idx});
                    }
            }
        }

        return max_time;
    }
};
