class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /*
            if we find an interval that is overlapping remove the one

            sort the intervals in order
            if an interval is overlapping, get rid of the one that ends later
            
            ----
             ---
            --

            loop through the array and check if the current interval ends after the next one starts
                That is overlapping
            need to track the previous one (the one we didnt remove)

                 ---
                ---
              ----
             ---
            ---
        */

        std::sort(intervals.begin(), intervals.end(), std::less<std::vector<int>>());

        int res = 0;
        std::vector<int> prev_interval = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            std::vector<int> curr_interval = intervals[i];
            if (prev_interval[1] > curr_interval[0]) {
                prev_interval = (prev_interval[1] < curr_interval[1]) ? prev_interval : curr_interval;
                res++;
            } else {
                prev_interval = curr_interval;
            }
        }

        return res;
    }
};
