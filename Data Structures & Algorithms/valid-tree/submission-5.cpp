class Solution {
public:
    std::unordered_set<int> visited;
    std::unordered_set<int> cycle;
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
            tree if there are no cycles
            each node is connected

            adj list mapping all nodes to edges
            visited hashmap

            boolean dfs
            insert visited at the start and remove it at the end
            skip the parent node when iteratating through neighbours

            0 1
            1 0
            2 3
            3 2
        */

        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < edges.size(); ++i) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        if (!dfs(adj_list, 0, -1)) return false;
        if (visited.size() == n) return true;
        return false;
    }

    bool dfs(std::unordered_map<int, std::vector<int>>& adj_list, int course, int parent) {
        if (cycle.count(course)) return false;

        cycle.insert(course);
        visited.insert(course);

        std::vector<int> neighbours = adj_list[course];
        for (int i = 0; i < neighbours.size(); ++i) {
            if (neighbours[i] == parent) continue;
            if (!dfs(adj_list, neighbours[i], course)) return false;
        }

        cycle.erase(course);
        return true;
    }
};
