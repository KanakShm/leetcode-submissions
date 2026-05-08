class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        /*
            Generate edges on the fly
            start at edge 0 and look at all other edges
            append the one that is closest to the current node
            change the current node to the closest one 
            and repeat until we have appended all points 
        */

        int res = 0;
        int node = 0;
        std::unordered_set<int> visited;
        std::vector<int> dist(points.size(), INT_MAX);
        while (visited.size() < points.size() - 1) {
            visited.insert(node);
            int smallest_dist = INT_MAX;
            int next_node = -1;
            for (int i = 0; i < points.size(); ++i) {
                if (visited.count(i)) continue;
                int curr_dist = std::abs(points[node][0] - points[i][0]) + 
                           std::abs(points[node][1] - points[i][1]);
                dist[i] = std::min(dist[i], curr_dist);
                if (smallest_dist > dist[i]) {
                    next_node = i;
                    smallest_dist = dist[i];
                }
            }
            res += smallest_dist;
            node = next_node;
        }
        return res;     
    }
};
