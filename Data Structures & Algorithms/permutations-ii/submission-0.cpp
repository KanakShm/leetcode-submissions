class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*
            dfs -> running array that is the permuatation
                base case: i == nums.size() append the permutation to res
            for loop iterating through each element
            starts at j = 0
            visited array since we cant add duplicates to running array
                dont append any elements that are visited
                when we enter the backtrack we visit, 
                visited = false when we pop off
            dfs(j + 1)

            sort the nums array. In the for loop, if the next element is the same
            as the current, and j > 0 we continue

            1 2 3 4 5 6

            1 1 2
            1 2 1
            1
        */

        std::vector<bool> visited(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        std::vector<int> perm = {};
        dfs(nums, visited, perm, 0);
        return res;
    }

    void dfs(std::vector<int>& nums, std::vector<bool>& visited, std::vector<int>& perm, int i) {
        if (i == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (visited[j]) continue;
            if (j > 0 && nums[j] == nums[j - 1] && !visited[j - 1]) continue;
            perm.push_back(nums[j]);
            visited[j] = true;
            dfs(nums, visited, perm, i + 1);
            perm.pop_back();
            visited[j] = false;
        }
    }
};