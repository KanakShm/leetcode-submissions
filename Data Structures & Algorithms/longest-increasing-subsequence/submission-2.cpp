class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            Dynamic programming
            Recursion:
                Either choose the element i or dont
                Cannot choose if element i is less than previously chosen element (curr max)
            
            Base Case:
                if we are at the end of nums
                keep track of a global maximum
            
            Memoisation:
                If we stumble on i, then return the cached value

            Maintain vector
        */
        
        int global_max = 0;
        std::vector<int> sequence;
        dfs(nums, global_max, sequence, 0);
        return global_max;
    }

    void dfs(std::vector<int>& nums, int& global_max, std::vector<int>& sequence, int i) {
        if (i >= nums.size()) return;

        if (sequence.empty() || sequence.back() < nums[i]) {
            sequence.push_back(nums[i]);
            global_max = std::max((int)sequence.size(), global_max);
            dfs(nums, global_max, sequence, i + 1);

            sequence.pop_back();
        }

        dfs(nums, global_max, sequence, i + 1);
    }
};
