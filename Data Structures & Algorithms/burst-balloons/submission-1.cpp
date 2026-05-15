class Solution {
public:
    int maxCoins(vector<int>& nums) {
        /*
            Top down dynamic programming
            DFS function loops through nums and considers each 
            number to be the last one to pop
            current = 1 - everything we have popped to the left *
                      1 + everything we have popped to the righ *
                      current index
            Then add this result to the dfs of the left and the
            dfs to the right

            dp with left and right indices
        */

        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(nums.size(), -1));
        return dfs(nums, dp, 0, nums.size() - 1);
    }

    int dfs(std::vector<int>& nums, std::vector<std::vector<int>>& dp, int l, int r) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        // Run through the array and pop each balloon last
        int max_amount = 0;
        for (int i = l; i <= r; ++i) {
            int first = 1;
            int second = nums[i];
            int third = 1;
            
            if (l - 1 >= 0) first = nums[l - 1];
            if (r + 1 < nums.size()) third = nums[r + 1];
            int coins = first * second * third;
            max_amount = std::max(max_amount, coins + 
                        dfs(nums, dp, l, i - 1) + 
                        dfs(nums, dp, i + 1, r));
            dp[l][r] = max_amount;
        }

        return dp[l][r];
    }
};
