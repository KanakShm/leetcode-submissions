class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        /*  
            sort meetings by start time ascending
            loop through meetings and assign to an n that is 
            not used

            create int array of total meetings in a specific room
            size of n.

            only use one room at a time
            pop all rooms that have been freed
                if the current meeting starts after the top ends
        */
        std::sort(meetings.begin(), meetings.end());
        std::vector<int> used_rooms(n, 0);
        std::priority_queue<int, std::vector<int>, std::greater<>> rooms;
        for (int i = 0; i < n; ++i) {
            rooms.push(i);
        }

        int time = 0;
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<>> cooldown;
        for (int i = 0; i < meetings.size(); ++i) {
            int end = meetings[i][1];
            // If time has elapsed past the first meeting end then pop it
            while (!cooldown.empty() && cooldown.top()[0] <= meetings[i][0]) {
                rooms.push(cooldown.top()[1]);
                cooldown.pop();
            }
            
            // If all rooms are being used, pop the top of cooldown
            // the meeting needs to end later because we need to "wait"
            // for the meeting to finish
            if (rooms.empty()) {
                rooms.push(cooldown.top()[1]);
                end = cooldown.top()[0] + (meetings[i][1] - meetings[i][0]);
                cooldown.pop();
            }
            
            // Use the room
            int room = rooms.top();
            rooms.pop();
            cooldown.push({end, room});

            used_rooms[room]++;
        }

        int max_count = 0;
        int res = 0;
        for (int i = 0; i < used_rooms.size(); ++i) {
            if (used_rooms[i] > max_count) {
                max_count = used_rooms[i];
                res = i;
            }
        }

        return res;
    }
};