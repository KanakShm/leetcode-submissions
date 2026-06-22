class Solution {
public:
    int findMin(vector<int> &nums) {
        /*
            Always look at right first
            if mid < right
                array increasing to the right so high = mid - 1
            if mid > right
                the left most value is going to be larger than the rightmost
                value so the minimum exists to the right
        */

        int high = nums.size() -1;
        int low = 0;

        int res = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= nums[high]) {
                res = std::min(res, nums[mid]);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};
