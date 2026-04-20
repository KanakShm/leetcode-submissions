class Solution {
public:
    std::unordered_set<std::string> visited;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        /*
         a - b = 4
         b - a 0.25
         build adjacency list <letter, <letter,division>>

         iterate through the queries start at c and dfs to d.
         keep track of res
        */

        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> adj_list;
        for (int i = 0; i < equations.size(); ++i) {
            adj_list[equations[i][0]].push_back(std::make_pair(equations[i][1], values[i]));
            adj_list[equations[i][1]].push_back(std::make_pair(equations[i][0], 1 / values[i]));
        }

        std::vector<double> res;
        for (int i = 0; i < queries.size(); ++i) {
            if (adj_list.find(queries[i][0]) == adj_list.end()) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(dfs(adj_list, queries[i][0], queries[i][1], 1));
        }

        return res;
    }

    double dfs(std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& adj_list,
    std::string& start, std::string& target, double divisor) {
        if (adj_list.find(start) != adj_list.end() && start == target) return divisor;
        visited.insert(start);

        std::vector<std::pair<std::string, double>> neighbours = adj_list[start];
        for (int i = 0; i < neighbours.size(); ++i) {
            std::string next = neighbours[i].first;
            if (visited.count(next)) continue;
            double next_div = divisor * neighbours[i].second;
            double res = dfs(adj_list, next, target, next_div);
            if (res != -1.0) {
                visited.erase(start);
                return res;
            }
        }

        visited.erase(start);
        return -1.0;
    }
};