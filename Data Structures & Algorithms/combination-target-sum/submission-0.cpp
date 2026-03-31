class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        /*
            backtracking
            dfs approach where we iterate through nums recursively
            keep track of current num sum and current vector
            base case is if current sum is greater than the target return
            if the crurrent sum is equal to target append to result array
        */
        std::vector<std::vector<int>> result;
        int curr_sum = 0;
        std::vector<int> group;
        int i = 0;
        dfs(i, nums, target, result, curr_sum, group);
        return result;
    }

    inline void dfs(int i, const std::vector<int>& nums, const int target, std::vector<std::vector<int>>& result, int curr_sum, std::vector<int> group) {
        if (i >= nums.size()) {
            return;
        }
        if (curr_sum == target) {
            result.push_back(group);
            return;
        } else if (curr_sum > target) {
            return;
        }

        group.push_back(nums[i]);
        curr_sum += nums[i];
        dfs(i, nums, target, result, curr_sum, group);

        group.pop_back();
        curr_sum -= nums[i];
        dfs(i + 1, nums, target, result, curr_sum, group);
    }
};
