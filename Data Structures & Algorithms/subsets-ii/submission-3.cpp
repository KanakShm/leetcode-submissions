class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
            Each subset may contain duplicate characters only if they
            exist in nums

            Backtracking -> All possible of a value

            For loop starting at j = i -> Only look ahead
            base case if i > nums.size() push subset to res and return
            dfs (j + 1) -> dont re add the current element
            Only start a subset with a unique number
                if j > i and nums j == nums i then continue and dont 
                add anything to the current res

            1 1 2

            1 1 2
            1 1

            1 2
            1 2
            1
            2
        */
        std::sort(nums.begin(), nums.end());
        std::vector<int> subset = {};
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
