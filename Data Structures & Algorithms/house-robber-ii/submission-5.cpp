class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            Need to consider every possibility
            backtracking:
                either select the house to rob or dont
                if you select it you move index i + 2
                if you dont select it you move i + 1
            
            keep a global count variable

            memoisation:
                if we have visited the index before then return its value
                update dp array value after each dfs search
        */

        std::vector<int> dp(nums.size(), -1);
        std::vector<int> left;
        std::vector<int> right;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                left.push_back(nums[i]);
            } else if (i == nums.size() - 1) {
                right.push_back(nums[i]);
            } else {
                left.push_back(nums[i]);
                right.push_back(nums[i]);
            }
        }

        int a = dfs(left, dp, 0);
        std::fill(dp.begin(), dp.end(), -1);
        int b = dfs(right, dp, 0);

        return std::max(a, b);
    }

    int dfs(std::vector<int>& nums, std::vector<int>& dp, int i) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        // choose the current number
        int a = nums[i] + dfs(nums, dp, i + 2);

        // dont choose the current number
        int b = dfs(nums, dp, i + 1);

        dp[i] = std::max(a, b);
        return dp[i];
    }
};
