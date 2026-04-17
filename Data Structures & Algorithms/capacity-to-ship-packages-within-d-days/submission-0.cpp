class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        /*
            max weight >= largest number
            create min heap
            start at largest weight
            iterate through the array and group numbers until the sum > max weight
                decrement days
            
            if we get to the end of the array with days <= 0 we found the number
            else pop off the heap and add to the max weight
            
            O(n^2)
            O(n)

            max weight ever needed is the sum of everything
            binary search between these two elements

            for each mid value you iterate through the entire array and decrement day everytime
            we form a group, if at the end the day is > 0 go down, if it is < 0 go up, if = 0 return
            2 8 4 2
        */

        int low = INT_MIN;
        int high = 0;
        for (int i = 0; i < weights.size(); ++i) {
            low = std::max(weights[i], low);
            high += weights[i];
        }

        int min_capacity = high;
        while (low <= high) {
            int mid = (low + high) / 2;

            int i = 0;
            int days_needed = 1;
            int curr_weight = 0;
            for (int i = 0; i < weights.size(); ++i) {
                if (curr_weight + weights[i] > mid) {
                    curr_weight = 0;
                    days_needed++;
                }
                curr_weight += weights[i];
            }

            if (days_needed <= days) {
                min_capacity = mid;
                high = mid - 1;
            } else if (days_needed > days) {
                low = mid + 1;
            }
        }

        return min_capacity;
    }
};