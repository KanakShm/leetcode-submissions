class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /*
            Backtracking:
            pick the element until it goes over the target
            if it equals the target res++

            Dynamic Programming:
            State variable is the target
            0 1 2 3 4
            7 4 2 1 1

            dp array starting from the back, initialise target as 1
            decrement for loop through nums array and += all of the dp with curr amount + nums
            return dp[0]
        */

        std::vector<int> dp(target + 1, 0);
        dp[target] = 1;

        for (int amount = target - 1; amount >= 0; --amount) {
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (amount + nums[i] > target) continue;
                count += dp[amount + nums[i]];
            }
            dp[amount] = count;
        }

        return dp[0];
    }
};