class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            create a hashmap key = course and value = array of prereqs
            dfs through the array till you dont find the element in hashmap (doesnt need prereq)
            add that to the return vector
            backtrack to the next element in array and dfs

            [0,1], [0,2], [0,3], [1,2], [2,3] 
            3 2 1 0

            hashmap: 0, 1,2,3
                     1, 2
                     2, 3

            if a list is finished update to empty list
        */

        std::unordered_map<int, std::vector<int>> umap;
        for (int i = 0; i < numCourses; ++i) {
            umap[i] = {};
        }

        for (int i = 0; i < prerequisites.size(); ++i) {
            umap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        std::vector<int> res;
        std::unordered_set<int> visited;
        for (int i = 0; i < numCourses; ++i) {
            std::unordered_set<int> cycle;
            if (!dfs(umap, res, i, cycle, visited)) {
                return {};
            }
        }

        return res;
    }

    bool dfs(std::unordered_map<int, std::vector<int>>& umap, std::vector<int>& res, int course,
             std::unordered_set<int>& cycle, std::unordered_set<int>& visited) {
        if (cycle.find(course) != cycle.end()) {
            return false;
        }
        
        if (umap[course].empty()) {
            if (visited.find(course) == visited.end()) {
                res.push_back(course);
                visited.insert(course);
            }
            return true;
        }

        std::vector<int> prereqs = umap[course];
        cycle.insert(course);
        for (int i = 0; i < prereqs.size(); ++i) {
            if (!dfs(umap, res, prereqs[i], cycle, visited)) {
                return false;
            }
        }

        umap[course] = {};
        res.push_back(course);
        visited.insert(course); 
        cycle.erase(course);
        return true;
    }
};
