class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /*

            ----
        -----   --------

        scan the intervals, keep count of how many intervals are currently
        overlapping
        When there are two or more, you have to remove the one that ends last
        increase a count when an interval has started.
        keep track of the end
        when another interval's start < end, increase count and update end to be
        the min of the current and prev

        [[0,2],[1,3],[2,4],[3,5],[4,6]]
        */
        std::sort(intervals.begin(), intervals.end());
        int global_end = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < global_end) {
                res++;
                global_end = std::min(global_end, intervals[i][1]);
            } else {
                global_end = std::max(global_end, intervals[i][1]);
            }
        }
        return res;
    }
};
