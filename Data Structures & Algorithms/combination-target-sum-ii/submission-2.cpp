class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*
            all possibilites so need backtracking
            sort the array
            dfs
                take the number then i + 1
                for loop j = i to all the elements
                if the for loop is at the first element and it is the same
                as the previous element just increment
                    if we start at the same value then we have already accounted for
                    those subsets
            1 2 2 4 5 6 9
        */

        std::sort(candidates.begin(), candidates.end());
        std::vector<int> subset = {};
        dfs(candidates, 0, 0, target, subset);
        return res;
    }

    void dfs(std::vector<int>& candidates, int i, int sum, int target, std::vector<int>& subset) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(subset);
            return;
        }

        for (int j = i; j < candidates.size(); ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) continue;
            subset.push_back(candidates[j]);
            dfs(candidates, j + 1, sum + candidates[j], target, subset);
            subset.pop_back();
        }
    }
};
