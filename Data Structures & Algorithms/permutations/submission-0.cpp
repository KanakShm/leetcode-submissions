class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*
            dfs to the end of nums
            add that number to local array and push to global result
            backtrack to the previous number
            for each element in the global result array
                append the current number to the start, middle(s) and end
            make sure this new array is updated
            keep backtracking back up until global result has all of its local arrays the size of nums
        */

        std::vector<std::vector<int>> result = {{}};
        std::vector<int> local;

        for (int i = 0; i < nums.size(); ++i) {
            std::vector<std::vector<int>> new_perms;
            for (int j = 0; j < result.size(); ++j) {
                // for each element in the result i want to append the current number in each place
                for (int k = 0; k <= result[j].size(); ++k) {
                    std::vector<int> curr = result[j];
                    curr.insert(curr.begin() + k, nums[i]);
                    new_perms.push_back(curr);
                }
            }
            result = new_perms;
        }
        return result;
    }   
};
