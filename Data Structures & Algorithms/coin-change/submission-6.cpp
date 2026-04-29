class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
            DP array with amount as state variable
            12 - 0 coins needed
            11 - 1 coin needed
            10 - how many coins needed to get to 11 plus whatever is at 11
                loop through the entire array and sum dp[curr_sum + picked coin] + 1
                return / save the value that is the minimum

            1 5 10

            0 1 2 3 4 5 6 7 8 9 10 11 12
                              3  2  1  0
        */              

        std::vector<int> dp(amount + 1, -1);
        dp[amount] = 0;

        for (int money = amount - 1; money >= 0; --money) {
            int min_coins_needed = amount + 1;
            for (int i = 0; i < coins.size(); ++i) {
                if (money + coins[i] > amount) continue;
                min_coins_needed = std::min(1 + dp[money + coins[i]], min_coins_needed);
            }
            dp[money] = min_coins_needed;
        }

        return dp[0] >= amount + 1 ? -1 : dp[0];
    }
};
