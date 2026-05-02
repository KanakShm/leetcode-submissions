class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        /*
            Backtracking -> recursing with i
            base case is when permute.size() = nums.size() push back to res array
            for loop starting from 0
            dfs with j + 1 -> cannot pick the same number
            visited array so we skip numbers already in the permute array
        */
        std::vector<bool> visited(nums.size(), false);
        std::vector<int> permute = {};
        dfs(nums, permute, visited);
        return res;
    }

    void dfs(std::vector<int>& nums, std::vector<int>& permute, std::vector<bool>& visited) {
        if (permute.size() == nums.size()) {
            res.push_back(permute);
            return;
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (visited[j]) continue;
            permute.push_back(nums[j]);
            visited[j] = true;
            dfs(nums, permute, visited);
            permute.pop_back();
            visited[j] = false;
        }
    }
};
