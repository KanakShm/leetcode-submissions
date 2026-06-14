class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*
            if mid < high -> array sorted to the right
                if target in between mid and high then go right
                else go left
                
            else array sorted to the left
                if target in between left and mid then go left
                else go right

            final case where left mid and right are the same left++
        */

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) return true;

            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                continue;
            }

            if (nums[mid] <= nums[right]) {
                if (nums[mid] <= target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (nums[mid] >= target && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return false;
    }
};