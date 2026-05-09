class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
            2D DP bottom up approach
            at each amount we ask how many ways there are starting from the ith coin
            do we need to reach amount
                this is done by checking taking the coin at i, decrementing the amount
                and finding out how many ways to make the lowered amount -> storing that
                then also checking down (to skip the current coint) and adding the total
                from both right and down checks
            
            amount 0 1 2 3 4
                1. 1 1 1 1 1
                2. 1 1 2 2 3
                3. 1 1 2 3 4
            
            return 4
        */

        std::vector<std::vector<int>> dp(coins.size(), std::vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 1;
        }

        for (int i = 0; i < coins.size(); ++i) {
            for (int curr_amount = 1; curr_amount < amount + 1; ++curr_amount) {
                int total = 0;
                if (curr_amount - coins[i] >= 0) {
                    total += dp[i][curr_amount - coins[i]];
                }

                if (i - 1 >= 0) {
                    total += dp[i - 1][curr_amount];
                }
                dp[i][curr_amount] = total;
            }
        }
        
        return dp[coins.size() - 1][amount];
    }
};
