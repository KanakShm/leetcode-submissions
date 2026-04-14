class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        /*
            graph can contain cycles
            create adjacency list hashmap<int, vector neighbour>
            for loop from 0 to n - 1
            visited set and if i is visited we continue
            dfs my way through a connected component
            every time the dfs returns we add a count
            return the count

            insert into hashet (visited)
            for loop through all the neighbours
            if there is a neighbour we have visited just continue

            0 2,3
            1 3
            2 0, 3
            3 0, 2
            4

            have a parent node and a current node
            while dfsing for loop through the neighbours
                if the new node is equal to the parent node then continue
        */

        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < n; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < edges.size(); ++i) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        int res = 0;
        std::unordered_set<int> visited;
        for (int i = 0; i < n; ++i) {
            if (visited.count(i)) continue;
            dfs(adj_list, visited, i, -1);
            res++;
        }

        return res;
    }

    void dfs(std::unordered_map<int, std::vector<int>>& adj_list, std::unordered_set<int>& visited, 
            int current_node, int parent_node) 
    {
            visited.insert(current_node);

            std::vector<int> neighbours = adj_list[current_node];
            for (int i = 0; i < neighbours.size(); ++i) {
                int new_node = neighbours[i];
                if (visited.count(new_node)) continue;
                dfs(adj_list, visited, new_node, current_node);
            }
    }
};
