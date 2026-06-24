class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
            no duplicate subsets -> sort the array
                if j > 0 and we are at the same number, dont include it
                basically we cant start at the same number a second time
            have a visited hashset
        */

        std::vector<int> subset;
        std::sort(nums.begin(), nums.end());
        dfs(nums, subset, 0);
        return res;
    }

    void dfs(std::vector<int>& nums, std::vector<int>& subset, int i) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            subset.push_back(nums[j]);
            dfs(nums, subset, j + 1);
            subset.pop_back();
        }

        res.push_back(subset);
    }
};
