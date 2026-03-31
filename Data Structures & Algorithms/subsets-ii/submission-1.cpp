class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
            all possible subsets will require some backtracking
            sort the array
            you can either choose the current number or not choose it
            push current number
            backtrack(i+1)
            pop current number
            since we dont want duplicates we enter a while loop until we get to the first element
            that is not the current element. 
            backtrack(i+1)
            base case is when i == nums.size() push to global array and return;

            1 1 2. i = 2
            1 1    i = 2
            1 2    i = 2
            1
            2
            []      final push back
        */

        std::vector<std::vector<int>> result;
        std::vector<int> subset;
        std::sort(nums.begin(), nums.end(), std::less<int>());
        backtrack(0, result, nums, subset);
        return result;
    }

    void backtrack(int i, std::vector<std::vector<int>>& result, const std::vector<int>& nums, std::vector<int> subset) {
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(i + 1, result, nums, subset);

        subset.pop_back();
        // To get rid of duplicates we never 'add' the same element again after removal. just skip that number
        while (i < nums.size() - 1 && nums[i] == nums[i+1])
            i++;
        
        backtrack(i + 1, result, nums, subset);
    }
};
