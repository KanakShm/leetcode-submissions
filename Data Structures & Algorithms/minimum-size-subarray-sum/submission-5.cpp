class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*
            while subbarray sum < target increment right and add to 
            res
            while >= target move left pointer forward and decrement res
            return min right - left + 1
        */

        int left = 0;
        int right = 0;
        int sum = 0;
        int res = INT_MAX;
        while (left < nums.size()) {
            if (right < nums.size() && sum < target) {
                sum += nums[right];
                right++;
            } else {
                if (sum >= target) res = std::min(res, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};