class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            Dynamic programming: Bottom up approach
            Start two pointers at the end
            initialise DP array with all ones
            for every i, loop through to the end of the array and ask
                if j > i, if it is update the DP array
            
            i  j
            [1,4,2,3,2,2,1]             
            [9,1,4,2,3,3,7]
        */

        std::vector<int> dp(nums.size(), 1);
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    int new_dp = std::max(dp[i], 1 + dp[j]);
                    dp[i] = new_dp;
                }
            }
        }

        int max = INT_MIN;
        for (int i = 0; i < dp.size(); ++i) {
            max = std::max(max, dp[i]);
        }

        return max;
    }
};  
