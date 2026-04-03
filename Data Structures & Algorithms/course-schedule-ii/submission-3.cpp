class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            we must take the prereqs before taking the course
            create adjacency list with course and all its prereqs (hashmap)
            dfs through this until we find a course that doesnt have prereqs
                add this to the result
                backtrack up
            
            complete the array and add the current element to the result
            keep track of all elements we have added so far (hashmap)

            detect cycles:
                each dfs call we add to a hashset (beginning)
            
            1 [2,3,4]
            2 [3, 4]
            3 [4]
            4 [ ]
        */

        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < numCourses; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < prerequisites.size(); ++i ) {
            adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        std::vector<int> res;
        std::unordered_set<int> cycle;
        std::unordered_set<int> visited;
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, adj_list, cycle, visited, res)) {
                return {};
            }
        }

        return res;
    }

    bool dfs(int course, std::unordered_map<int, std::vector<int>>& adj_list, std::unordered_set<int>& cycle, 
             std::unordered_set<int>& visited, std::vector<int>& res) 
    {
        if (cycle.count(course)) return false;
        if (visited.count(course)) return true;

        visited.insert(course);
        cycle.insert(course);
        std::vector<int> prerequisites = adj_list[course];
        for (int i = 0; i < prerequisites.size(); ++i) {
            if (!dfs(prerequisites[i], adj_list, cycle, visited, res)) {
                return false;
            }
        }

        res.push_back(course);
        cycle.erase(course);
        adj_list[course] = {};
        return true;
    }
};
