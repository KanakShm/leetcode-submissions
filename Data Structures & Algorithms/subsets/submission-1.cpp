class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
            knapsack pick one then leave it
            1 2 3
            1 2
            1 3
            1
            2 3
            2
            3
            []
            recurse with i, when i == nums size append to res
        */
        std::vector<int> subset = {};
        dfs(nums, subset, 0);
        return res;
    }

    void dfs(std::vector<int>& nums, std::vector<int>& subset, int i) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, subset, i + 1);

        subset.pop_back();
        dfs(nums, subset, i + 1);
    }
};
