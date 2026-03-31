class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        /*
            do dfs
            first create a hashmap of undirected nodes
                node, array of edges
            
            while visited. size < n
                dfs
                add one to total tally
            
            return the tally

            dfs:
                base case if node has been visited there is a cycle just return
                we go through the array of edges and dfs through each one of them
                be careful of dfs a parent this will result in an infinite loop
        */

        std::unordered_map<int, std::vector<int>> umap;
        std::unordered_set<int> visited;

        for (int i = 0; i < n; ++i) {
            umap[i] = {};
        }

        for (int i = 0; i < edges.size(); ++i) {
            umap[edges[i][0]].push_back(edges[i][1]);
            umap[edges[i][1]].push_back(edges[i][0]);
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (visited.count(i)) continue;
            dfs(umap, visited, i, -1, umap[i]);
            components++;
        }

        return components;
    }

    void dfs(std::unordered_map<int, std::vector<int>>& umap, std::unordered_set<int>& visited,
             int node, int parent, std::vector<int>& neighbours)
    {
        if (visited.count(node)) return;
        visited.insert(node);

        for (int i = 0; i < neighbours.size(); ++i) {
            if (neighbours[i] == parent) continue;
            dfs(umap, visited, neighbours[i], node, umap[neighbours[i]]);
        }
    }
};
