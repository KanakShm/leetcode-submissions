class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
            sort intervals by start time
            iterate through all intervals keep track of current and next
            if curr end > next start the intervals overlap,
                create a new interval that encloses both of them and
                set that as the curr interval
        */
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> res;
        std::vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            std::vector<int> next = intervals[i];
            if (curr[1] >= next[0]) {
                curr[0] = std::min(curr[0], next[0]);
                curr[1] = std::max(curr[1], next[1]);
                continue;
            }

            res.push_back(curr);
            curr = next;
        }

        res.push_back(curr);

        return res;
    }
};
