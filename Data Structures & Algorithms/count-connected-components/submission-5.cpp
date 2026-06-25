class Solution {
public:
    std::unordered_set<int> visited;
    int countComponents(int n, vector<vector<int>>& edges) {
        /*
            connected components where we have visited
            dfs through graph
            adjacency list containing all elements
            look out for cycles and dont consider them to avoid infinite loops
            for loop from 0 to n and dfs in each iteration
        */

        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < n; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < edges.size(); ++i) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        int count = 0;
        std::unordered_set<int> cycle;
        for (int i = 0; i < n; ++i) {
            if (visited.count(i)) continue;
            dfs(adj_list, i);
            count++;
        }

        return count;
    }

    void dfs(std::unordered_map<int, std::vector<int>>& adj_list, int node) {
        if (visited.count(node)) return;
        visited.insert(node);

        std::vector<int> neighbours = adj_list[node];
        for (int i = 0; i < neighbours.size(); ++i) {
            if (visited.count(neighbours[i])) continue;
            dfs(adj_list, neighbours[i]);
        }

    }
};
