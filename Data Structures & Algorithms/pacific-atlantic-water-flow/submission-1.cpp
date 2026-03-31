class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*
            from the pacific and atlantic oceans, check which nodes can be reached using breadth first
            search.
            only append to the queue if the value is greater than the current. Keep track of pacific 
            and atlantic bool visited arrays and dont append if we have already appended them
            run two bfs
        */

        std::vector<std::vector<bool>> pacific(heights.size(), std::vector<bool>(heights[0].size(), false));
        std::vector<std::vector<bool>> atlantic(heights.size(), std::vector<bool>(heights[0].size(), false));

        std::queue<std::pair<int, int>> pacQueue;
        std::queue<std::pair<int, int>> atlQueue;

        for (int i = 0; i < heights.size(); ++i) {
            pacific[i][0] = true;
            pacQueue.push(std::make_pair(i, 0));

            atlantic[i][heights[0].size() - 1] = true;
            atlQueue.push(std::make_pair(i, heights[0].size() - 1));
        }

        for (int i = 0; i < heights[0].size(); ++i) {
            pacific[0][i] = true;
            pacQueue.push(std::make_pair(0, i));

            atlantic[heights.size() - 1][i] = true;
            atlQueue.push(std::make_pair(heights.size() - 1, i));
        }

        // Update the visited arrays for each ocean
        bfs(heights, pacQueue, pacific);
        bfs(heights, atlQueue, atlantic);

        std::vector<std::vector<int>> res;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[0].size(); ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    void bfs(std::vector<std::vector<int>>& heights, 
             std::queue<std::pair<int, int>>& q, 
             std::vector<std::vector<bool>>& visited)
    {
        while (!q.empty()) {
            std::pair<int, int> node = q.front();
            q.pop();

            // check right, bottom, left and up if it can be added/visited
            if (node.second + 1 < heights[0].size() && !visited[node.first][node.second + 1] && 
                heights[node.first][node.second + 1] >= heights[node.first][node.second]) {
                q.push(std::make_pair(node.first, node.second + 1));
                visited[node.first][node.second + 1] = true;
            }

            if (node.first + 1 < heights.size() && !visited[node.first + 1][node.second] && 
                heights[node.first + 1][node.second] >= heights[node.first][node.second]) {
                q.push(std::make_pair(node.first + 1, node.second));
                visited[node.first + 1][node.second] = true;
            }

            if (node.second - 1 >= 0 && !visited[node.first][node.second - 1] && 
                heights[node.first][node.second - 1] >= heights[node.first][node.second]) {
                q.push(std::make_pair(node.first, node.second - 1));
                visited[node.first][node.second - 1] = true;
            }

            if (node.first - 1 >= 0 && !visited[node.first - 1][node.second] && 
                heights[node.first - 1][node.second] >= heights[node.first][node.second]) {
                q.push(std::make_pair(node.first - 1, node.second));
                visited[node.first - 1][node.second] = true;
            }
        }
    }
};
