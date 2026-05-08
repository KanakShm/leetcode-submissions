class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        /*
            Construct an adjacency list of all points i to j with their weights
            dijkestra through this     
        */

        std::unordered_map<int, std::vector<std::pair<int, int>>> adj_list;
        for (int i = 0; i < points.size(); ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = std::abs(x1 - x2) + std::abs(y1 - y2);

                adj_list[i].push_back({dist, j});
            }
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> min_heap;
        std::unordered_set<int> visited;
        int total_cost = 0;
        min_heap.push({0, 0});
        while (visited.size() != points.size()) {
            std::pair<int, int> node = min_heap.top();
            min_heap.pop();

            if (visited.count(node.second)) continue;
            total_cost += node.first;

            visited.insert(node.second);

            std::vector<std::pair<int, int>> neighbours = adj_list[node.second];
            for (int i = 0; i < neighbours.size(); ++i) {
                if (visited.count(neighbours[i].second)) continue;
                min_heap.push({neighbours[i].first, neighbours[i].second});
            }
        }

        return total_cost;
    }
};
