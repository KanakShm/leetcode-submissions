class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
            breadth first search while a queue is not empty
            start at the rotten fruit
            append the neighbour values to the queue
            pop the current value
            keep track of count which will be the timer that we return
            first count how many fruit there are
            decrement this counter every time we pop from the queue
            if this counter becomes zero by the end we return the timer count, if not return -1
            there may be multiple fruits
            could have an array of pairs<int, int> for all the rotten fruit locations
            and each time we add to the queue we iterate through this vector and add those elements as well

            1,1,0
            0,1,1
            0,1,2
        */

        int num_of_fruits = 0;
        std::vector<std::pair<int, int>> initial_rotten;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) {
                    num_of_fruits++;
                }
                if (grid[i][j] == 2) {
                    initial_rotten.push_back(std::make_pair(i, j));
                    num_of_fruits--;
                }
            }
        }



        // Push all current rotten fruits
        std::queue<std::vector<std::pair<int, int>>> q;
        q.push(initial_rotten);

        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        for (int i = 0; i < initial_rotten.size(); ++i) {
            visited[initial_rotten[i].first][initial_rotten[i].second] = true;
        }

        // bfs while the queue is not empty
        int time = 0;
        while (!q.empty()) {
            std::vector<std::pair<int, int>> rotten_fruit = q.front();
            q.pop();

            // iterate through all the current rotten fruits and push neighbours to the queue
            std::vector<std::pair<int, int>> next_rotten;
            for (int i = 0; i < rotten_fruit.size(); ++i) {
                // Add right, down, left and up. Dont add if already visited
                if (rotten_fruit[i].second + 1 < grid[0].size() && grid[rotten_fruit[i].first][rotten_fruit[i].second + 1] && !visited[rotten_fruit[i].first][rotten_fruit[i].second + 1]) {
                    next_rotten.push_back(std::make_pair(rotten_fruit[i].first, rotten_fruit[i].second + 1));
                    visited[rotten_fruit[i].first][rotten_fruit[i].second + 1] = true;
                    num_of_fruits--;
                }
                if (rotten_fruit[i].first + 1 < grid.size() && grid[rotten_fruit[i].first + 1][rotten_fruit[i].second] && !visited[rotten_fruit[i].first + 1][rotten_fruit[i].second]) {
                    next_rotten.push_back(std::make_pair(rotten_fruit[i].first + 1, rotten_fruit[i].second));
                    visited[rotten_fruit[i].first + 1][rotten_fruit[i].second] = true;
                    num_of_fruits--;
                }
                if (rotten_fruit[i].second - 1 >= 0 && grid[rotten_fruit[i].first][rotten_fruit[i].second - 1] && !visited[rotten_fruit[i].first][rotten_fruit[i].second - 1]) {
                    next_rotten.push_back(std::make_pair(rotten_fruit[i].first, rotten_fruit[i].second - 1));
                    visited[rotten_fruit[i].first][rotten_fruit[i].second - 1] = true;
                    num_of_fruits--;
                }
                if (rotten_fruit[i].first - 1 >= 0 && grid[rotten_fruit[i].first - 1][rotten_fruit[i].second] && !visited[rotten_fruit[i].first - 1][rotten_fruit[i].second]) {
                    next_rotten.push_back(std::make_pair(rotten_fruit[i].first - 1, rotten_fruit[i].second));
                    visited[rotten_fruit[i].first - 1][rotten_fruit[i].second] = true;
                    num_of_fruits--;
                }
            }
            if (!next_rotten.empty()) {
                q.push(next_rotten);
                time++;
            }
            std::cout << "time: " << time << " fruits: " << num_of_fruits << std::endl;

        }


        if (num_of_fruits > 0) {
            return -1;
        }

        return time;
    }
};
