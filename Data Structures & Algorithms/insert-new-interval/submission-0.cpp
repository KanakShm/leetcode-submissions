class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
            append all intervals that end before the new one starts
            when we find an interval that ends after new one starts
                merge intervals by getting the min of the start of current and new
                max of the end of current and new
                set this as new interval
                break this loop when we find an interval with start > new interval end
                push the new interval before breaking
            
            iterate through the end and keep adding more intervals
        */

        std::vector<std::vector<int>> res;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(intervals[i][0], newInterval[0]);
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            i++;
        }
        
        res.push_back(newInterval);

        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;

    }
};
