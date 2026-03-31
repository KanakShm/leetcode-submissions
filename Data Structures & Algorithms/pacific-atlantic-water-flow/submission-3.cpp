class Solution {
public:
    std::vector<std::vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*
            Pacific bfs from j = 0 and i = 0
            Atlantic bfs from i = m and j = n

            load pacific and atlantic into queue

            neighbours are reachable iff they are greater than current cell

            Every node reachable we increment the count of that index in result array
            finally traverse the array and every number that is 2 gets added to the resultant vector
        */        
        std::vector<std::vector<bool>> pac_vis(heights.size(), std::vector<bool>(heights[0].size(), false));
        std::vector<std::vector<bool>> atl_vis(heights.size(), std::vector<bool>(heights[0].size(), false));

        std::queue<std::vector<int>> q_atl;
        std::queue<std::vector<int>> q_pac;
        

        for (int i = 0; i < heights[0].size(); ++i) {
            q_atl.push(std::vector<int>{(int)heights.size() - 1, i});
            atl_vis[heights.size() - 1][i] = true;

            q_pac.push({0, i});
            pac_vis[0][i] = true;
        }

        for (int i = 0; i < heights.size(); ++i) {
            q_atl.push(std::vector<int>{i, (int)heights[0].size() - 1});
            atl_vis[i][heights[0].size() - 1] = true;

            q_pac.push(std::vector<int>{i, 0});
            pac_vis[i][0] = true;
        }

        // BFS through the queues and append result to reachable
        bfs(heights, q_atl, atl_vis);
        bfs(heights, q_pac, pac_vis);

        std::vector<std::vector<int>> res;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[0].size(); ++j) {
                if (atl_vis[i][j] && pac_vis[i][j]) {
                    res.push_back(std::vector<int>{i, j});
                }
            }
        }

        return res;
    }

    void bfs(std::vector<std::vector<int>>& heights, std::queue<std::vector<int>>& ocean, std::vector<std::vector<bool>>& visited) 
    {
        while (!ocean.empty()) {
            std::vector<int> cell = ocean.front();
            ocean.pop();

            // check if neighbours are reachable
            for (int i = 0; i < dir.size(); ++i) {
                int row = cell[0] + dir[i][0];
                int col = cell[1] + dir[i][1];

                if (row >= 0 && col >= 0 && row < heights.size() && col < heights[0].size() &&
                    heights[row][col] >= heights[cell[0]][cell[1]] && !visited[row][col]) 
                    {
                        ocean.push(std::vector<int>{row, col});
                        visited[row][col] = true;
                    }
            }
        }
    }

};
