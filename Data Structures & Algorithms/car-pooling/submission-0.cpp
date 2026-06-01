class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        /*
            sort by start time
            fill another array of size equal to the max end and init
            to 0
            go through the new array and initialise start index with
            + passengers and end index with -= passengers
            iterate through this array and sum all values and
            if this exceeds capacity at any point return false
            otherwise return true
        */
        int max_end = 0;
        for (int i = 0; i < trips.size(); ++i) {
            max_end = std::max(trips[i][2], max_end);
        }

        std::vector<int> routes(max_end + 1, 0);
        for (int i = 0; i < trips.size(); ++i) {
            int passengers = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
            routes[start] += passengers;
            routes[end] -= passengers;
        }

        int curr_passengers = 0;
        for (int i = 0; i < routes.size(); ++i) {
            curr_passengers += routes[i];
            if (curr_passengers > capacity) return false;
        }

        return true;
    }
};