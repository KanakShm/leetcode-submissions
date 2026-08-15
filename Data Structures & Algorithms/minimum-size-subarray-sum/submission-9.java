class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        /*
            sliding window
            increase window size
            shrink window size until while >= target
                update the min window size
        */

        int res = Integer.MAX_VALUE;
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < nums.length) {
            sum += nums[right];
            while (left <= right && sum >= target) {
                res = Math.min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return res == Integer.MAX_VALUE ? 0 : res;
    }
}