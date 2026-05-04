class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
            Time it takes for the last node to get the signal starting from k
            adjacency list vector with neighbour node and weight
            directed graph
            Dijkestra
            heap <weight, node>
            push neighbours to heap
            pop min

            visited array so we know all nodes have been visited

            1
            2 4
            3 4
            4 4
            visit when we pop
        */

        std::unordered_map<int, std::vector<std::pair<int, int>>> adj_list;
        for (int i = 0; i < n; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < times.size(); ++i) {
            adj_list[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        int min_time = 0;
        std::unordered_set<int> visited;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
        q.push({0, k});
        
        while (!q.empty()) {
            std::pair<int, int> top = q.top();
            int node = top.second;
            int weight = top.first;
            q.pop();
            if (visited.count(node)) continue;
            visited.insert(node);

            min_time = weight;

            std::vector<std::pair<int, int>> neighbours = adj_list[node];
            for (int i = 0; i < neighbours.size(); ++i) {
                if (visited.count(neighbours[i].first)) continue;
                q.push({neighbours[i].second + weight, neighbours[i].first});
            }
        }

        if (visited.size() != n) return -1;
        return min_time;
    }
};
