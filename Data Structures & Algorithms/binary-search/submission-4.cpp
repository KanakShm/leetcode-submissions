class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
            Check middle index. If it is greater move to the left sub array else move right
            how to iterate pointer: size/2 -> (size - idx) / 2 or (size + idx) /2
            end if the index is greater than or less than 0 - nums.size() -1 or we have found the target

            [0, 1, 2, 3]
        */

        int high = nums.size() - 1;
        int low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
