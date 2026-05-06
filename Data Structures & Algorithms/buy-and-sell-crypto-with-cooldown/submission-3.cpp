class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            index you are on, weather you can buy or sell
            1 3 4 0 4
                    0
                    0
                
            Backtracking:
            either buy the stock, sell the stock or leave the stock
                recurse i + 1       i + 2               i + 1
            keep track of is buying state meaning we have to eather buy the stock
            or skip the stock
        */

        bool is_buying = true;
        std::vector<std::vector<int>> dp(2, std::vector<int>(prices.size(), -1));
        return dfs(prices, 0, is_buying, dp);
    }

    int dfs(std::vector<int>& prices, int i, bool is_buying, std::vector<std::vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }

        if (dp[is_buying][i] != -1) return dp[is_buying][i];

        if (is_buying) {
            int cooldown = dfs(prices, i + 1, is_buying, dp);
            int buy = dfs(prices, i + 1, !is_buying, dp) - prices[i];
            dp[is_buying][i] = std::max(cooldown, buy);
        } else {
            int cooldown = dfs(prices, i + 1, is_buying, dp);
            int sell = prices[i] + dfs(prices, i + 2, !is_buying, dp);
            dp[is_buying][i] = std::max(cooldown, sell);
        }

        return dp[is_buying][i];
    }
};
