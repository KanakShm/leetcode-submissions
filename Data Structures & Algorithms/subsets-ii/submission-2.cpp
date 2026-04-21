class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
            backtracking
            pick one element or dont pick that element 
            sort the array. Only add unique elements at each dfs level

            dfs can pick any element. Dont pick an element already in the subset
                boolean visited array
            
            for loop starting from 0
            dfs(j + 1)
            base case i == size return
            at the end append to the res array

            1 1 2
            1 1 2
            1 2
        */
        std::sort(nums.begin(), nums.end());
        std::vector<bool> visited(nums.size(), false);
        std::vector<int> subset;
        dfs(nums, visited, 0, subset);
        return res;
    }

    /*
        121
        12
        11
        1
        21
        2
        1
    */

    void dfs(std::vector<int>& nums, std::vector<bool>& visited, int i, std::vector<int>& subset) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        

        for (int j = i; j < nums.size(); ++j) {
            if (visited[j] || (j > i && nums[j - 1] == nums[j])) continue;
            subset.push_back(nums[j]);
            visited[j] = true;
            dfs(nums, visited, j + 1, subset);
            subset.pop_back();
            visited[j] = false;
        }

        res.push_back(subset);
    }
};
