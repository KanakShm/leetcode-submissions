class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        /*
            traverse the graph and keep track of min height of each node
            height is calculated as max depth
               0 - 1 - 3 - 2
                   |
                   4
            
            0 1
            1 0 3
            2 3
            3 1 2
            4 1
            
            create adjacency list of edges
            for each n, dfs and calculate the depth
            store depth in var array of length n
            dfs
                starts with 0, each dfs increment 1
                return max of dfs return and current depth
            go through the list and get the highest number return that in an array
        */

        
        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < n; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < edges.size(); ++i) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        std::vector<std::pair<int,int>> heights(n);
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> visited;
            heights[i].first = dfs(adj_list, visited, i, 0);
            heights[i].second = i;
        }

        std::sort(heights.begin(), heights.end());
        std::vector<int> res;
        int mht = heights[0].first;
        int idx = 0;
        while (idx < n && heights[idx].first == mht) {
            res.push_back(heights[idx].second);
            idx++;
        }

        return res;
    }

    int dfs(std::unordered_map<int, std::vector<int>>& adj_list, std::unordered_set<int>& visited, int node, int depth) {
        if (visited.count(node)) return depth - 1;
        
        visited.insert(node);
        int res = depth;
        std::vector<int> neighbours = adj_list[node];
        for (int i = 0; i < neighbours.size(); ++i) {
            if (visited.count(neighbours[i])) continue;
            res = std::max(res, dfs(adj_list, visited, neighbours[i], depth + 1));
        }

        return res;
    }
};