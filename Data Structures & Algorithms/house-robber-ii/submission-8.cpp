class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            do bottom up twice -> one for left array and one for right
            take last two elements and fill them with their respective numbers
            dp[i] = dp[i] + dp[i + 2] or dp[i + 1]

            dp[0 0 0 0 0 0 0 0]
        */
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        std::vector<int> dp_a(nums.size() - 1, -1);
        std::vector<int> dp_b(nums.size() - 1, -1);

        std::vector<int> left;
        std::vector<int> right;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                left.push_back(nums[i]);
            } else if (i == nums.size() - 1) {
                right.push_back(nums[i]);
            } else {
                left.push_back(nums[i]);
                right.push_back(nums[i]);
            }
        }

        rob_houses(left, dp_a);
        rob_houses(right, dp_b);

        return std::max(dp_a[0], dp_b[0]);
    }

    void rob_houses(std::vector<int>& nums, std::vector<int>& dp) {
        int last_idx = std::max((int)nums.size() - 1, 0);
        int second_last_idx = std::max((int)nums.size() - 2, 0);

        dp[last_idx] = nums[last_idx];
        dp[second_last_idx] = std::max(nums[last_idx], nums[second_last_idx]);

        for (int i = dp.size() - 3; i >= 0; --i) {
            dp[i] = std::max(nums[i] + dp[i + 2], dp[i + 1]);
        }
    }
};
