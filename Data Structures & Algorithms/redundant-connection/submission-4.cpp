class Solution {
public:
    std::unordered_set<int> visited;
    std::unordered_set<int> cycle;
    int cycle_start = -1;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
            create adjacecny list hashmap<int, neighbours (vector)>
            dfs through this list and iterate through all neighbours
            visited hash set checks if a node has been visited before
            if it has then that is our edge
            append all edges that form a cycle to res vector
            put the res vector into hashset <arry>
            iterate backwards from edges list and return the first one that appears
            in hashset
            dont add the parent to dfs and that is not a cycle either

            1 2 3
            2 1 4
            3 1 4
            4 3 2
        */

        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < edges.size(); ++i) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(adj_list, 1, -1);

        for (int i = edges.size() - 1; i >= 0; --i) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (cycle.count(u) && cycle.count(v)) {
                return edges[i];
            }
        }
        return {};
    }

    bool dfs(std::unordered_map<int, std::vector<int>>& adj_list, int curr, int parent) {
        if (visited.count(curr)) {
            cycle_start = curr;
            return true;
        }

        visited.insert(curr);
        std::vector<int> neighbours = adj_list[curr];
        for (int i = 0; i < neighbours.size(); ++i) {
            int next_node = neighbours[i];
            if (next_node == parent) continue;
            if (dfs(adj_list, next_node, curr)) {
                // We are backtracking from a cycle
                if (cycle_start != -1) {
                    cycle.insert(next_node);
                }

                if (curr == cycle_start) {
                    cycle_start = -1;
                }
                return true;
            }
        }

        return false;
    }
};
