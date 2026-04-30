class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        /*
            1 [0]
            2 [1]
            3 [2]

            store the course and its prereqs into hashmap<int, vector of int> adj list
            0 [1]
            1 [2]
            2 [3]

            0 1
            3 1
            start at vj and dfs until you find uj or you search the entire graph
            and dont find anything

            boolean dfs bubble up true
            for loop looping through all the neighbours and dfssing into them
            directed graph -> if we find a cycle return false?
                visited set array add when you enter and remove when you leave
        */

        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < numCourses; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < prerequisites.size(); ++i) {
            adj_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        std::vector<bool> res(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            std::vector<int> dp(numCourses, -1);
            res[i] = dfs(adj_list, queries[i][1], queries[i][0], dp);
        }

        return res;
    }

    bool dfs(std::unordered_map<int, std::vector<int>>& adj_list, int course1, int course2, std::vector<int>& dp) {
        if (course1 == course2) {
            dp[course1] = 1;
            return true;
        }
        if (dp[course1] != -1) return dp[course1];

        std::vector<int> prerequisites = adj_list[course1];
        for (int i = 0; i < prerequisites.size(); ++i) {
            if (dfs(adj_list, prerequisites[i], course2, dp)) {
                dp[course1] = 1;
                return true;
            }
        }

        dp[course1] = 0;
        return false;
    }
};