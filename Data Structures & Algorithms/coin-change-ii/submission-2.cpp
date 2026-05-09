class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
            state variable amount
            coins index we take
            iterate through each amount and only take that coin in that row
            backtrack how many ways and store in 2d DP table
        */

        std::vector<std::vector<int>> dp(coins.size() + 1, std::vector<int>(amount + 1, -1));
        return dfs(coins, amount, 0, dp);
    }

    int dfs(std::vector<int>& coins, int amount, int i, std::vector<std::vector<int>>& dp) {
        if (amount == 0) return 1;
        if (i >= coins.size()) return 0;

        if (dp[i][amount] != -1) return dp[i][amount];

        int ways = 0;
        if (amount - coins[i] >= 0) {
            ways += dfs(coins, amount - coins[i], i, dp);
        }

        ways += dfs(coins, amount, i + 1, dp);

        dp[i][amount] = ways;
        return ways;
    }
};
