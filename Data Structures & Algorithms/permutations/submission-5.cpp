class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        /*
            for loop start at j = 0
            visited hashset of all current numbers in permutation
        */
        std::vector<int> permute;
        std::unordered_set<int> visited;
        dfs(nums, permute, visited);
        return res;
    }

    void dfs(std::vector<int>& nums, std::vector<int>& permute, std::unordered_set<int>& visited) {
        if (permute.size() == nums.size()) {
            res.push_back(permute);
            return;
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (visited.count(nums[j])) continue;
            permute.push_back(nums[j]);
            visited.insert(nums[j]);
            dfs(nums, permute, visited);
            permute.pop_back();
            visited.erase(nums[j]);
        }
    }
};
