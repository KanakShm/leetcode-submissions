class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            Add each course and prereqs into a hashmap
            for each course dfs with its prereqs
                for each prereq dfs into that course to find how many prereqs it has
                if we find that it has no prereqs return true
                keep iteratating
                once the entire vector has been traversed and we find that all courses
                can be taken, replace the current subject's prereqs with an empty vector
                we know that a course cannot be taken if we have visited it already
                hence keep track of visited hashmap that resets after each dfs backtrack in wrapper func
                0, 1 2
                1, 2
                2, 
            [0, 1] [2, 1]
        */
        std::unordered_map<int, std::vector<int>> umap;
        for (int i = 0; i < numCourses; ++i) {
            umap[i] = {};
        }

        for (int i = 0; i < prerequisites.size(); ++i) {
            umap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            std::unordered_map<int, int> visited;
            if (!dfs(i, umap, visited)) {
                return false;
            }
        }
        return true; 
    }

    bool dfs(int course, std::unordered_map<int, std::vector<int>>& umap, std::unordered_map<int, int>& visited) {
        if (visited.find(course) != visited.end()) return false;
        if (umap[course].empty()) return true;

        visited[course]++;

        // We go through each prereq for the course
        std::vector<int> prereqs = umap[course];
        for (int i = 0; i < prereqs.size(); ++i) {
            if (!dfs(prereqs[i], umap, visited)) {
                return false;
            }
        }
        visited.erase(course);
        return true;
    }
};
