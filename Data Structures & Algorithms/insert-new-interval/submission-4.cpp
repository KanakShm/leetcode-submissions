class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
            iterate until the start of the new interval is greater than
            the end of the current interval

            need to overlap if new end > next start
                new interval becomes new start, next end
        */

        std::vector<std::vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval[0] <= intervals[i][1]) break;
            res.push_back(intervals[i]);
        }

        int idx = res.size();
        while (idx < intervals.size() && newInterval[1] >= intervals[idx][0]) {
            newInterval[0] = std::min(intervals[idx][0], newInterval[0]);
            newInterval[1] = std::max(intervals[idx][1], newInterval[1]);
            idx++;
        }

        res.push_back(newInterval);
        for (int i = idx; i < intervals.size(); ++i) {
            res.push_back(intervals[i]);
        }

        return res;
    }
};
