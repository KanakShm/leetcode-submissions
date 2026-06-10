class Solution {
public:
    std::vector<int> res;
    std::unordered_set<int> cycle;
    std::unordered_set<int> completed;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            0 1
            1
            2 0 1
            3 4
            4

            0 1
            1


            adj list <course, vector of prereqs needing to take>
            go from course 0 to n courses
            every time dfs through the vector of prereqs,
                only mark course complete if prereqs have been traversed
            if we see a cycle return empty array (no valid arrangement)
                put a course in hashset then traverse that course
                if you see the same course in the cylce hashset then there is a cycle
                remove the course from the hashset once at the end of dfs function
            
            dont do infinte loops
                if we have already completed a course add it to completed hashset
        */

        std::unordered_map<int, std::vector<int>> adj_list;
        for (int i = 0; i < numCourses; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < prerequisites.size(); ++i) {
            adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!completed.count(i) && !dfs(adj_list, i)) return {};
        }

        return res;
    }

    bool dfs(std::unordered_map<int, std::vector<int>>& adj_list, int course) {
        if (cycle.count(course)) return false;

        cycle.insert(course);
        std::vector<int> prerequisites = adj_list[course];
        for (int i = 0; i < prerequisites.size(); ++i) {
            if (completed.count(prerequisites[i])) continue;
            if (!dfs(adj_list, prerequisites[i])) return false;
        }

        res.push_back(course);
        completed.insert(course);
        cycle.erase(course);
        return true;
    }
};
