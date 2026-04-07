class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*  
            start left and right at idx 0;
            take the most amount of gas possible at each station
            total += gas - cost
            if the total goes below 0, then we cant reach the station.
            update left to right + 1
            increment the right pointer if total is above 0

            if left goes out of bounds then return -1

            do another pass starting at the left index
        */

        int left = 0;
        int right = 0;
        int total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += (gas[right] - cost[right]);
            if (total < 0) {
                left = right + 1;
                total = 0;
            }
            right++;
        }

        if (left >= gas.size()) return -1;

        total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            int idx = (left + i) % gas.size();
            total += (gas[idx] - cost[idx]);
            if (total < 0) return -1;
        }

        return left;
    }
};