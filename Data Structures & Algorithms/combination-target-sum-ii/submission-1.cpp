class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*
            Backtracking since we need to return all unique combinations
            sort the array
            dfs -> keep choosing numbers until you hit the target
                target is reached you append to res array
                if sum greater than target return
            knapsack, either choose the number and add to running sum or dont

            2 2 2 2 2 3 1 6
            2 2 2 -> last added is 2
            2 2 
            Should only start with a unique number, when you pop you cant push the same element on again

            1 2 2 4 5 6 9
        */

        std::sort(candidates.begin(), candidates.end());
        std::vector<int> combination = {};
        dfs(candidates, combination, -1, 0, 0, target);
        return res;
    }

    void dfs(std::vector<int>& candidates, std::vector<int>& combination, int parent, int curr_sum, int i, int target) {
        if (curr_sum == target) {
            res.push_back(combination);
            return;
        }
        
        if (curr_sum > target || i == candidates.size()) return;

        // Add the current element
        if (candidates[i] != parent) {
            curr_sum += candidates[i];
            combination.push_back(candidates[i]);
            dfs(candidates, combination, -1, curr_sum, i + 1, target);

            curr_sum -= candidates[i];
            combination.pop_back();
            dfs(candidates, combination, candidates[i], curr_sum, i + 1, target);
        } else {
            dfs(candidates, combination, parent, curr_sum, i + 1, target);
        }
    }
};
