class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*
            sliding window
            expand window until >= target
            while sum > target shrink from the left
                update res
        */

        int sum = 0;
        int left = 0;
        int right = 0;
        int res = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right];

            while (left <= right && sum >= target) {
                res = std::min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return res == INT_MAX ? 0 : res;
    }
};