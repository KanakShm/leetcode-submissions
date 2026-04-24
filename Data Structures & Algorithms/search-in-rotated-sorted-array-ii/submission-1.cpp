class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*
            if high >= mid then pivot is on left side
                if target exists within high and mid shift here
            if low <= mid then pivot is on right side
                if target exists within low and mid shift here

            6786

            1131
        */

        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[low] == target) return true;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                continue;
            }
            if (nums[mid] == target) return true;
            if (nums[high] >= nums[mid]) {
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else if (nums[low] <= nums[mid]) {
                if  (target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return false;
    }
};