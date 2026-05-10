class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            state vector being nums and i
            each element in dp array is the number of ways to get to that target sum
            at each index, choose that number +- and add whatevr there is currently + whatever
            there is in the element you came from
        */

        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
        }

        std::vector<std::unordered_map<int, int>> dp(nums.size() + 1);
        dp[0][0] = 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            std::unordered_map<int, int> curr_sum_to_ways = dp[i];
            for (auto iter = curr_sum_to_ways.begin(); iter != curr_sum_to_ways.end(); ++iter) {
                dp[i + 1][iter->first + nums[i]] += dp[i][iter->first];
                dp[i + 1][iter->first - nums[i]] += dp[i][iter->first];
            }
        }
        return dp[nums.size()][target];
    }
};
