class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*  
            Backtracking since we need to go through all possibilities
            sort the array
            For loop within our dfs
                j = 0
                dont add already visited elements
                dont add the same element as the start to a permutation
                base case is if permutation size is the same as nums size
        */

        std::sort(nums.begin(), nums.end());
        std::vector<int> permutation = {};
        std::vector<bool> visited(nums.size(), false);
        dfs(nums, permutation, visited);
        return res;
    }

    void dfs(std::vector<int>& nums, std::vector<int>& permutation, std::vector<bool>& visited) {
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (visited[j]) continue;
            if (j > 0 && nums[j] == nums[j - 1] && !visited[j - 1]) continue;
            permutation.push_back(nums[j]);
            visited[j] = true;
            dfs(nums, permutation, visited);
            permutation.pop_back();
            visited[j] = false;
        }
    }
};