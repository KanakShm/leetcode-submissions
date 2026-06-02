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
            find how many rooms overlap at once
            initialise array of size of the max end
            iterate through intervals and += start index and -= end index
            iterate through the array and add each element to res count
            return the max res we saw
        */
        int max_end = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            max_end = std::max(max_end, intervals[i].end);
        }

        std::vector<int> rooms(max_end + 1, 0);
        for (int i = 0; i < intervals.size(); ++i) {
            rooms[intervals[i].start]++;
            rooms[intervals[i].end]--;
        }

        int rooms_needed = 0;
        int curr_rooms = 0;
        for (int i = 0; i < rooms.size(); ++i) {
            curr_rooms += rooms[i];
            rooms_needed = std::max(rooms_needed, curr_rooms);
        }

        return rooms_needed;
    }
};
