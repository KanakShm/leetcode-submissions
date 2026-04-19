class Solution {
public:
    int rob(vector<int>& nums) {
        /*

            DP is concerned with ehat is the best value i can take at the current
            time. Take the highest value contained in taking the current ohsue or not
            taking the current house.

            max money from array 1 and 2
            
            bottom up:
                pick the last house
                i - 1 = max(i - 1, i)
                iterate backwards like that
            
            top down:
                rob the current house or dont rob the current house
                    i + 2                       i + 1
                
                dp[i] becomes the max of taking the house and not taking the house
        */

        if (nums.size() == 1) return nums[0];

        std::vector<int> houses_a(nums.begin() + 1, nums.end());
        std::vector<int> houses_b(nums.begin(), nums.end() - 1);

        std::vector<int> dp_a(nums.size() - 1, -1);
        std::vector<int> dp_b(nums.size() - 1, -1);

        int first = dfs(houses_a, dp_a, 0);
        int second = dfs(houses_b, dp_b, 0);

        return std::max(first, second);
    }

    int dfs(std::vector<int>& houses, std::vector<int>& dp, int i) {
        if (i >= houses.size()) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        // pick the house
        int rob = houses[i] + dfs(houses, dp, i + 2);

        // dont pick the house
        int leave = dfs(houses, dp, i + 1);

        dp[i] = std::max(rob, leave);
        return dp[i];
    }
};
