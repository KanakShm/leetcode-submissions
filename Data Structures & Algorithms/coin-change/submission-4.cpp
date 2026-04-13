class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
            Use amount as dp problem
            every iteration we can choose any of the coins
                for loop through the coins (unlike house robbers where the order chosen matters)
            
            each iteration we check if the amount is 0 or has gone overboard
            dfs returns the minimum number of coins needed to get from the current amount to the target
        */

        std::vector<int> dp(amount + 1, -1);
        int res = dfs(coins, dp, amount);
        if (res == INT_MAX) return -1;
        return res;
    }

    int dfs(std::vector<int>& coins, std::vector<int>& dp, int amount) {
        // If we are at the end we dont need to choose any more coins
        if (amount == 0) return 0;

        // We had already chosen that coin in the previous iteration so dont choose it as 
        // it goes beyond scope
        if (amount < 0) return -1;
        if (dp[amount] != -1) return dp[amount];

        int min_coins = INT_MAX;
        // Choose every coin and return the minimum number of coins to get the target
        for (int i = 0; i < coins.size(); ++i) {
            if (amount - coins[i] >= 0) {
                int no_coins = dfs(coins, dp, amount - coins[i]);
                if (no_coins != INT_MAX) {
                    min_coins = std::min(min_coins, 1 + no_coins);
                }
            }
        }

        dp[amount] = min_coins;
        return dp[amount];
    }
};
