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
    int minMeetingRooms(vector<Interval>& intervals) {
        /*

        ------
        ------------------
                    ----
        0 1 2 ... 38 39 40

        O(n * m)

        start array and end array both sorted
        increment the counter that is minimum, if it is the start array then increment a count,
        if it is the end array decrement the count. Keep global running max count

        0   5 15
        10 20 40
        */

        int max_count = 0;
        std::vector<int> start;
        std::vector<int> end;
        for (int i = 0; i < intervals.size(); ++i) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }

        std::sort(start.begin(), start.end(), std::less<int>());
        std::sort(end.begin(), end.end(), std::less<int>());

        int s = 0;
        int e = 0;
        int active_meetings = 0;
        while (e < end.size()) {
            if (s < start.size() && start[s] < end[e]) {
                active_meetings++;
                s++;
            } else {
                active_meetings--;
                e++;
            }

            max_count = std::max(active_meetings, max_count);
        }

        return max_count;
    }
};
