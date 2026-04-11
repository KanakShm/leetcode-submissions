class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            Each course has some prerequisites
            Build an adjacency list of the course and its prerequisites
            DFS through each of the course's prerequisites
            base case is if a course doesnt have a prerequiste we return
                return
            
            Cycle detection:
                visited hashset for each dfs 
                the same course cannot appear again as we traverse through the list of prereqs
            
            Iterate through each course's prereqs and append the course to the res after each dfs return
            dfs return will be after a whole iteration of the courses prereqs

            0  1
            1  2, 3, 0
            2  4
            3
            4
            [0, 1], [1, 3], [2, 4], [1, 2]
        */

        std::unordered_map<int, std::vector<int>> prereqs;
        for (int i = 0; i < numCourses; ++i) {
            prereqs[numCourses] = {};
        }

        for (int i = 0; i < prerequisites.size(); ++i) {
            prereqs[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        std::unordered_set<int> cycle;
        std::unordered_set<int> visited;
        std::vector<int> res;
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(prereqs, i, cycle, visited, res)) {
                return {};
            }
        }

        return res;
    }
    /*
        0  1
        1  2, 3, 0
        2  4
        3
        4
        [0, 1], [1, 3], [2, 4], [1, 2]
    */

    bool dfs(std::unordered_map<int, std::vector<int>>& prereqs, int course, std::unordered_set<int>& cycle, std::unordered_set<int>& visited, std::vector<int>& res) {
        if (cycle.count(course)) return false;

        if (visited.count(course)) return true;

        cycle.insert(course);
        visited.insert(course);

        std::vector<int> to_complete = prereqs[course];
        for (int i = 0; i < to_complete.size(); ++i) {
            if (!dfs(prereqs, to_complete[i], cycle, visited, res)) {
                return false;
            }
        }

        res.push_back(course);
        cycle.erase(course);
        return true;
    }
};
