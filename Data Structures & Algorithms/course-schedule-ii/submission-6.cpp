class Solution {
public:
    std::vector<int> res;
    std::unordered_set<int> visited;
    std::unordered_set<int> completed;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            adjacency list hashmap of course to its prereqs
            iterate through all the courses
            dfs on each one and go through all its prereqs
            output starts from the end of the dfs
            if a course depends on itself return -1
                visited array
                insert in the dfs
                remove when we exit
            
            1 2 3 4
            2 3
            3
            4 2 3

            0 1
            1
        */

        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < numCourses; ++i) {
            adj_list[numCourses] = {};
        }

        for (int i = 0; i < prerequisites.size(); ++i) {
            adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (completed.count(i)) continue;
            if (!dfs(adj_list, i)) return {};
        }

        return res;
    }

    bool dfs(std::unordered_map<int, std::vector<int>>& adj_list, int course) {
        if (visited.count(course)) return false;
        
        visited.insert(course);
        std::vector<int> neighbours = adj_list[course];

        for (int i = 0; i < neighbours.size(); ++i) {
            if (completed.count(neighbours[i])) continue;
            if (!dfs(adj_list, neighbours[i])) {
                return false;
            }
        }

        res.push_back(course);
        completed.insert(course);
        visited.erase(course);
        return true;
    }
};
