class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*
            dfs approach
            have a global result that we return
            if the target is reached append the local group
            iterate i through dfs
        */

        int curr_sum = 0;
        std::vector<std::vector<int>> result;
        std::vector<int> group;
        std::sort(candidates.begin(), candidates.end(), std::less<int>());
        dfs(0, candidates, target, result, group, curr_sum);
        return result;
    }

    inline void dfs(int i, const std::vector<int>& candidates, 
                    const int target, std::vector<std::vector<int>>& result, 
                    std::vector<int> group, int curr_sum) {
        if (curr_sum == target) {
            /*
                for loop with hash set
                each contains an array
                if that array matches the current array
            */
            result.push_back(group);
            return;
        }

        if (i >= candidates.size() || curr_sum > target) {
            return;
        }

        group.push_back(candidates[i]);
        curr_sum += candidates[i];
        dfs(i + 1, candidates, target, result, group, curr_sum);

        group.pop_back();

        while (i < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++; // we dont want to re add the same element we got rid of because we'll eventually find the same soltion with that
        }
        curr_sum -= candidates[i];
        dfs(i + 1, candidates, target, result, group, curr_sum);

    }
};
