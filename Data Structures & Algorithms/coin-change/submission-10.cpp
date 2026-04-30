class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
            amount is the state variable
            for loop to choose a coin only if the current money + that is less
            than amount

            base case if money = amount return 0
            each iteration we ask how many coins to get to amount from current amount


            [1,5,10]      12
            0 1 2 3 4 5 6 7 8 9 10 11 12
            4  3  2  5  4 3 2  1  4  3  2   1



                if we land on that amount again we can return the fewest number of coins 
                needed from that position till the target + 1
                dp is the minimum of the coins
        */

        std::vector<int> dp(amount + 1, -1);
        dp[amount] = 0;
        int res = dfs(coins, 0, amount, dp);
        return res == amount + 1 ? -1 : res;
    }

    int dfs(std::vector<int>& coins, int money, int amount, std::vector<int>& dp) {
        if (money == amount) return 0;
        if (dp[money] != -1) return dp[money];
        int min_coins = amount + 1;
        for (int i = 0; i < coins.size(); ++i) {
            if (amount - money < coins[i]) continue;
            int res = 1 + dfs(coins, money + coins[i], amount, dp);
            min_coins = std::min(min_coins, res);
        }

        dp[money] = min_coins;
        return min_coins;
    }
};
