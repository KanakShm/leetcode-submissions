class Solution {
public:
    int findMin(vector<int> &nums) {
        /*
            [3,4,5,6,1,2]
            [6,1,2,3,4,5]
            [1,2,3,4,5,6]
            [2,3,4,5,6,1]


            if we move to the left, and the numeber is bigger we
            know a smaller number exists somewhere in between so we move
            low up

            if mid number is lower than high number move down
            if mid number is higher than high number move up
        */
        int lowest_number = std::numeric_limits<int>::max();
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            lowest_number = std::min(lowest_number, nums[mid]);
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                high = mid - 1;
            } else {
                break;
            }
        }
        return lowest_number;
    }
};
