class Solution {
public:
    int cycle_start = -1;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
            dfs:
                when you find a cycle thats the start of the cycle
                add to res
                return true
                if dfs is true then add to res and return true
                otherwise dont do anything
            
        */

        std::vector<std::vector<int>> nodes;
        std::unordered_map<int, std::vector<int>> umap;
        std::unordered_set<int> visited;

        for (int i = 0; i < edges.size(); ++i) {
            umap[edges[i][0]].push_back(edges[i][1]);
            umap[edges[i][1]].push_back(edges[i][0]);
        }

        std::vector<std::vector<int>> res;
        dfs(umap, umap[1], visited, 1, -1, res);

        std::set<std::pair<int, int>> uset;
        for (int i = 0; i < res.size(); ++i) {
            int u = std::min(res[i][0], res[i][1]);
            int v = std::max(res[i][0], res[i][1]);

            uset.insert(std::make_pair(u, v));
        }

        for (auto iter = uset.begin(); iter != uset.end(); ++iter) {
            std::cout << (*iter).first << " " << (*iter).second << std::endl;
        }

        for (int i = edges.size() - 1; i >= 0; --i) {
            if (uset.count(std::make_pair(edges[i][0], edges[i][1]))) {
                return edges[i];
            }
        }
        return edges[0];
    }

    int dfs(std::unordered_map<int, std::vector<int>>& umap, std::vector<int>& neighbours,
        std::unordered_set<int>& visited, int node, int parent, std::vector<std::vector<int>>& res)
    
    {   
        if (visited.count(node)) {
            res.push_back({node, parent});
            cycle_start = node;
            return node;
        }

        visited.insert(node);

        // If we see that there is a number returned other than -1 that means we found a cycle
        for (int i = 0; i < neighbours.size(); ++i) {
            if (neighbours[i] == parent) continue;
            int recursive = dfs(umap, umap[neighbours[i]], visited, neighbours[i], node, res);
            if (recursive == 0) {
                return 0;
            } else if (recursive != -1) {
                if (node == cycle_start) {
                    return 0;
                }
                res.push_back({node, parent});
                return node;
            }
        }

        return -1;
    }
};
