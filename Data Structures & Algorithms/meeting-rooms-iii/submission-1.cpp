class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        /*
            sort by start time
            min heap for rooms that are available
            min heap for ongoing meetings
                <end time, room>
            loop through meetings and pop from available and push them onto ongoing
            while meetings should have ended pop from ongoing and push back to available


            [[1,10],[2,10],[3,10],[4,10]]
            [[1,20],[2,10],[4,5],[4,9][6,8]]

            [[2,13],[3,12],[7,10],[17,19],[18,19]]
        */
        std::sort(meetings.begin(), meetings.end());
        std::priority_queue<int, std::vector<int>, std::greater<>> available;
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> ongoing;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }

        std::vector<int> count(n, 0);
        for (int i = 0; i < meetings.size(); ++i) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            while (!ongoing.empty() && meetings[i][0] >= ongoing.top().first) {
                std::pair<int, int> finished_meeting = ongoing.top();
                ongoing.pop();
                available.push(finished_meeting.second);
            }

            if (available.empty()) {
                // take the meeting that ends first, finish it and delay the current ont
                auto finished_meeting = ongoing.top();
                ongoing.pop();
                end = finished_meeting.first + (end - start);
                available.push(finished_meeting.second);
            }

            int room = available.top();
            available.pop();
            ongoing.push({end, room});
            count[room]++;
        }

        int max = 0;
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] > count[max]) max = i;
        }

        return max;
    }
};