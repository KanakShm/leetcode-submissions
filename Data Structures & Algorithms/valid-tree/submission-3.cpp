class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
            contains no cycles
            connects all nodes

            build adjacency list node to edges
            0 1, 2, 3
            1 0, 4
            2 0
            3 0
            4 0

            visited set we add all nodes we have traversed
            for loop through the neighbours and add node to visited set
                each iteration add node to visited set

            cycle detection skip the parent node

            dfs through the adjacency list
        */
        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < n; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < edges.size(); ++i) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        std::unordered_set<int> visited;
        visited.insert(0);
        if (!dfs(adj_list, 0, -1, visited)) {
            return false;
        }

        return visited.size() == n;
    }

    bool dfs(std::unordered_map<int, std::vector<int>>& adj_list, int curr_node, int prev_node, std::unordered_set<int>& visited) {
        std::vector<int> neighbours = adj_list[curr_node];
        for (int i = 0; i < neighbours.size(); ++i) {
            int next_node = neighbours[i];
            if (next_node == prev_node) continue;
            if (visited.count(next_node)) return false;

            visited.insert(next_node);
            if (!dfs(adj_list, next_node, curr_node, visited)) return false;
        }

        return true;
    }
};
