class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            [1,4,4,5,2,4]
                139944
        */
        if (nums.size() == 1) return nums[0];

        std::vector<int> first_set(nums.begin(), nums.end() - 1);
        std::vector<int> second_set(nums.begin() + 1, nums.end());

        std::vector<int> dp(first_set.size(), -1);
        int first = bottomUp(dp, first_set);

        std::fill(dp.begin(), dp.end(), -1);
        int second = bottomUp(dp, second_set);

        return std::max(first, second);
    }

    int bottomUp(std::vector<int>& dp, std::vector<int>& houses) {
        if (houses.size() == 1) return houses[0];

        dp[houses.size() - 1] = houses[houses.size() - 1];
        dp[houses.size() - 2] = std::max(dp[houses.size() - 1], houses[houses.size() - 2]);

        for (int i = houses.size() - 3; i >= 0; --i) {
            int rob = houses[i] + dp[i + 2];
            int leave = dp[i + 1];
            dp[i] = std::max(rob, leave);
        }

        return dp[0];
    }
};
