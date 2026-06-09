class Solution {
public:
    std::vector<std::vector<int>> dir = {{0,1}, {1,0}, {0, -1}, {-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        /*
            multiple source bfs

            scan the grid for all rotten fruits and add to a queue
            start timer = 0
            every time you pop from the queue you increment the timer
            and you add all the oranges up down left and right to the 
            rotten queue
            you need to pop the entire queue at once since they are within
            the same time step
        */

        std::queue<std::pair<int, int>> rotten_fruits;
        int num_fruits = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    rotten_fruits.push({i,j});
                    num_fruits++;
                }
                if (grid[i][j] == 1) {
                    num_fruits++;
                }
            }
        }

        if (num_fruits == 0) return 0;
        
        int time = -1;
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        while (!rotten_fruits.empty()) {
            int n = rotten_fruits.size();
            for (int i = 0; i < n; ++i) {
                std::pair<int, int> cell = rotten_fruits.front();
                int curr_row = cell.first;
                int curr_col = cell.second;
                num_fruits--;

                rotten_fruits.pop();

                for (int j = 0; j < dir.size(); ++j) {
                    int next_row = curr_row + dir[j][0];
                    int next_col = curr_col + dir[j][1];

                    if (next_row < grid.size() && next_row >= 0 &&
                        next_col < grid[0].size() && next_col >= 0 &&
                        !visited[next_row][next_col] && grid[next_row][next_col] == 1) {
                            visited[next_row][next_col] = true;
                            rotten_fruits.push({next_row, next_col});
                        }
                }
            }
            time++;
        }

        return num_fruits ? -1 : time;
    }
};
