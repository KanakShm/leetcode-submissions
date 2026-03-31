class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
            DFS
            iterate thorugh the array of nums
            either add the curernt number or dont
            base case is if we have reached the end of the nums array
        */

        std::vector<std::vector<int>> output;
        std::vector<int> subset;
        dfs(0, output, subset, nums);
        return output;
    }

    void dfs(int i, std::vector<std::vector<int>>& output, std::vector<int> subset, std::vector<int>& nums) {
        if (i >= nums.size()) {
            output.push_back(subset);
            return;
        }

        // add current number to the subset
        subset.push_back(nums[i]);
        dfs(i + 1, output, subset, nums);

        // dont add current number to the subset
        subset.pop_back();
        dfs(i + 1, output, subset, nums);
    }
};
