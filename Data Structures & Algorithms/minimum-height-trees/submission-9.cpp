class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        /*
            append leaf nodes to the queue
            bfs down and always append leaf nodes
            once we reach the last 2 nodes, those sit at the centre of the graph
        */
        if (n == 1) return {0};

        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < n; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < edges.size(); ++i) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        std::vector<int> edge_count(n);
        std::queue<int> q;
        for (auto iter = adj_list.begin(); iter != adj_list.end(); ++iter) {
            edge_count[iter->first] = iter->second.size();
            if (iter->second.size() == 1) {
                q.push(iter->first);
            }
        }

        std::vector<int> res;
        while (!q.empty()) {
            if (n <= 2) {
                res.push_back(q.front());
                q.pop();
                continue;
            }
            
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int front = q.front();
                q.pop();
                n--;
                std::vector<int> neighbours = adj_list[front];
                for (int j = 0; j < neighbours.size(); ++j) {
                    edge_count[neighbours[j]]--;
                    if (edge_count[neighbours[j]] == 1) {
                        q.push(neighbours[j]);
                    }
                }
            }
        }

        return res;
    }
};