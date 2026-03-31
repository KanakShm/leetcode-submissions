class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
            Backtracking
                initially have everything in first subset (we know the size it is precomputed)
                Keep choosing elements recurisvely
                Keep track of size 1 and size 2
                First sum is sum of all elements
                second sum is second subset
            
            Base case:
                end of the array nums
                return true if sizes match (early return)
                return false at the end
            
            Memoisation:
                State represents current sum
                hashmap <int, bool>
            3
            [1,2,3,4]


            [1,2,3,4,5]
        */

        std::unordered_map<int, bool> memo;
        int first_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            first_sum += nums[i];
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (dfs(nums, memo, i, first_sum, 0)) {
                return true;
            }
        }
        return false;
    }

    bool dfs(std::vector<int>& nums, std::unordered_map<int, bool>& memo, int i, 
             int first_sum, int second_sum) {
        if (i >= nums.size()) {
            return false;
        }

        if (memo.find(first_sum) != memo.end()) {
            return memo[first_sum];
        }

        if (first_sum == second_sum) {
            memo[first_sum] = true;
            return true;
        }

        // always choose i and then iterate forward updating first and second sum
        second_sum += nums[i];
        first_sum -= nums[i];

        for (int j = i + 1; j < nums.size(); ++j) {
            if (dfs(nums, memo, j, first_sum, second_sum)) {
                return true;
            }
        }

        second_sum -= nums[i];
        first_sum += nums[i];
        
        return false;
    }
};
