class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
            sort the array
            res vector

            iterate through intervals
            initialise merged interval as ith interval
            if the next interval starts before current finishes, update the
                merged interval as max interval of current and next
            else 
                append the merged interval
            
            use a stack
                push onto the stack if intervals are unique
                pop from the stack if the intervals overlap and push the new interval
        */

        std::vector<std::vector<int>> unique_intervals;
        std::sort(intervals.begin(), intervals.end(), std::less<std::vector<int>>());
        unique_intervals.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            std::vector<int> top = unique_intervals.back();
            if (top[1] >= intervals[i][0]) {
                unique_intervals.pop_back();
                top[0] = std::min(top[0], intervals[i][0]);
                top[1] = std::max(top[1], intervals[i][1]);
                unique_intervals.push_back(top);
            } else {
                unique_intervals.push_back(intervals[i]);
            }
        }

        return unique_intervals;
    }
};
