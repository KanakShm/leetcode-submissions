class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
            start at the end of the array fill dp to 0
            decrement index backwards and ask if it is possible to get to the end from that element
            each decrement check the cells forward up to the value in the current index to see
                if they are non-zero.
        */

        std::vector<bool> dp(nums.size(), false);
        int idx = nums.size() - 1;
        dp[idx] = true;
        idx--;
        while (idx >= 0) {
            int max_jump_size = nums[idx];
            for (int i = 1; i <= max_jump_size; ++i) {
                if (idx + i < dp.size() && dp[idx + i] == true) {
                    dp[idx] = true;
                }
            }
            idx--;
        }

        return dp[0];
    }
};
