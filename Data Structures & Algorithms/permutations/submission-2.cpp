class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        /*
           backtracking
           pick the number, recurse dont pick the number
           for loop starts from 0 since we can look back
           cannot re add the same number so need a visited array and recurse with
           i + 1
            no visited hashset (doesnt matter numbers are distinct)

            1 2 3
            1 3 
        */
        std::vector<bool> visited(nums.size(), false);
        std::vector<int> permutation;
        dfs(nums, 0, permutation, visited);
        return res;
    }

    void dfs(std::vector<int>& nums, int i, std::vector<int>& permutation, std::vector<bool>& visited) {
        if (i == nums.size()) {
            res.push_back(permutation);
            return;
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (visited[j]) continue;
            permutation.push_back(nums[j]);
            visited[j] = true;
            dfs(nums, i + 1, permutation, visited);
            visited[j] = false;
            permutation.pop_back();
        }
    }
};
