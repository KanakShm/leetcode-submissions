class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*
            binary search
            if mid < high then shift happened on lhs
                if target is between mid and high move low up
                else move high down
            else it happend rhs
                if target is between mid and low move high down
                else move low up
            
            1 1 3 1
        */

        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return true;

            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                high--;
                continue;
            }

            if (nums[mid] <= nums[high]) {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (target < nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return false;
    }
};