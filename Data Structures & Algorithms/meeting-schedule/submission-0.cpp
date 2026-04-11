/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        /*
            return true if there are not overlaps, return false if there are
            add all intervals to a vector of vectors and sort by start time
            iterate through the array
        */

        std::vector<std::vector<int>> sorted_intervals;
        for (int i = 0; i < intervals.size(); ++i) {
            sorted_intervals.push_back({intervals[i].start, intervals[i].end});
        }

        std::sort(sorted_intervals.begin(), sorted_intervals.end(), std::less<std::vector<int>>());
        for (int i = 1; i < sorted_intervals.size(); ++i) {
            std::vector<int> prev_interval = sorted_intervals[i - 1];
            std::vector<int> curr_interval = sorted_intervals[i];
            if (prev_interval[1] > curr_interval[0]) {
                return false;
            }
        }

        return true;
    }
};
