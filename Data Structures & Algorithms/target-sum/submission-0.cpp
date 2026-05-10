class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            +-
            backtracking
            i
            choose + backtrack i + 1
            choose - backtrack i + 1

            +- sum of all nums
            i
            at index i what sum are we at -> backtrack
        */

        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
        }
        std::vector<std::vector<int>> dp(total * 2 + 1, std::vector<int>(nums.size(), -1));
        return dfs(nums, 0, 0, total, target, dp);
    }

    int dfs(std::vector<int>& nums, int i, int curr_sum, int total, int target, std::vector<std::vector<int>>& dp) {
        if (i == nums.size()) return curr_sum == target ? 1 : 0;
        if (dp[curr_sum + total][i] != -1) return dp[curr_sum + total][i];

        int ways = dfs(nums, i + 1, curr_sum + nums[i], total, target, dp) + 
                   dfs(nums, i + 1, curr_sum - nums[i], total, target, dp);
        
        dp[curr_sum + total][i] = ways;
        return dp[curr_sum + total][i];
    }
};
