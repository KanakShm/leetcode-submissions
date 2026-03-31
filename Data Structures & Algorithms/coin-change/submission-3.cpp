class Solution {
public:
    std::vector<int> cache;
    int coinChange(vector<int>& coins, int amount) {
        /*
            Use amount as the sub problem [0 - amount]
            Decision Tree:
                pick any one of the coins
            
            Backtrack:
                backtrack with new amount which is amount - coin
                res + 1
            
            Base Case:
                if amount = 0
                return res
            
            Result:
                minimum between current res and any backtracked res
            
            Memoisation:
                Cache array storing the amount from 0 -> amount. Make sure it is
                minimum
        */
        cache.resize(amount + 1, -1);
        int res = dfs(coins, amount);
        return res >= 1e9 ? -1 : res;
    }

    int dfs(std::vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (cache[amount] != -1) return cache[amount];

        int res = 1e9;
        for (int i = 0; i < coins.size(); ++i) {
            if (amount - coins[i] >= 0) {
                res = std::min(res, 1 + dfs(coins, amount - coins[i]));
            }
            cache[amount] = res;
        }

        return res;
    }
};
