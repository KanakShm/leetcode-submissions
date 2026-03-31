class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
            valid tree is a graph with no cycles and completely connected
            need to use a visited hash set
            dfs
            firstly lets put all nodes in a hashmap with array of connected nodes
            dfs through array of each node
            if current node is already visited then there is a cycle
            remove visited node from visited set after specific dfs search
        */

        std::unordered_map<int, std::vector<int>> umap;
        for (int i = 0; i < n; ++i) {
            umap[i] = {};
        }

        for (int i = 0; i < edges.size(); ++i) {
            umap[edges[i][0]].push_back(edges[i][1]);
            umap[edges[i][1]].push_back(edges[i][0]);
        }

        std::unordered_set<int> visited;
        return (dfs(umap, visited, 0, -1, umap[0]) && visited.size() == n);
    }
    /*
    0 [1,2,3]
    1 [0,4]
    2 [0]
    3 [0]
    4 [1]
    */
    bool dfs(std::unordered_map<int, std::vector<int>>& umap, std::unordered_set<int>& visited,
             int node, int parent, std::vector<int>& connections)
    {   
        std::cout << node << std::endl;
        if (visited.count(node)) return false;
        visited.insert(node);
        for (int i = 0; i < connections.size(); ++i) {
            if (connections[i] == parent) continue;
            if (!dfs(umap, visited, connections[i], node, umap[connections[i]])) {
                return false;
            }
        }
        return true;
    }
};
