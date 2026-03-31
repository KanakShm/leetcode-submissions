class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            create a hashmap of course and value being all its prereq
            for each course, dfs through each prereq and append to the res vector
            at the end of the func
            dfs should be a boolean where it returns false if you cant do the courses
        */

        std::unordered_map<int, std::vector<int>> courses;
        std::unordered_map<int, int> visited;

        for (int i = 0; i < numCourses; ++i) {
            courses[i] = {};
        }

        for (int i = 0; i < prerequisites.size(); ++i) {
            courses[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        // Iterate through all the courses and dfs the prereqs
        std::vector<int> res;
        std::unordered_map<int, int> added;
        for (int i = 0; i < numCourses; ++i) {
            if(!dfs(i, res, courses[i], courses, visited, added)) {
                return {};
            }
        }

        return res;
    }

    bool dfs(int course, std::vector<int>& res, std::vector<int>& prereqs, 
             std::unordered_map<int, std::vector<int>>& courses,
             std::unordered_map<int, int>& visited,
             std::unordered_map<int, int>& added)
    {
        if (visited.find(course) != visited.end()) {
            return false;
        }

        if (prereqs.empty()) {
            if (added.find(course) == added.end()) {
                added[course]++;
                res.push_back(course);
            }
            return true;
        }

        visited[course]++;
        for (int i = 0; i < prereqs.size(); ++i) {
            if (!dfs(prereqs[i], res, courses[prereqs[i]], courses, visited, added)) {
                return false;
            }
        }
        visited.erase(course);
        res.push_back(course);
        added[course]++;
        courses[course] = {};
        return true;
    }
};
