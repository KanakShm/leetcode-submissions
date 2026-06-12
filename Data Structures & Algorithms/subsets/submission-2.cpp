class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
            backtracking
            dfs
                knapsack - take the value or leave it

            [1 2 3]
            1 2 3
            1 2
            1 3
            1
            2 3
            2
            3

        */
        std::vector<int> curr;
        dfs(nums, curr, 0);
        return res;
    }

    void dfs(std::vector<int>& nums, std::vector<int>& curr, int i) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        // Take the element
        curr.push_back(nums[i]);
        dfs(nums, curr, i + 1);
        curr.pop_back();

        // Leave the element
        dfs(nums, curr, i + 1);
    }
};
