class Solution {
public:
    std::vector<int> cache;
    int rob(vector<int>& nums) {
        /*
            Decision tree:
                either pick the house and go two steps forward
                dont pick the house and go next step
            
            1 before:
                dfs picking the house and going 2 steps forward -> returning the money
                dfs not picking the house and going one forward -> dfs left if possible -> returning the money
                return the current sum + max of the left and right

            Base case:
                At the end of the nums[] array, return money

            Memoisation:
                vector of sums of length of nums
                at each index we store max value possible
                    for example if we are at the final element, we already know the max money 
                    we can get if we start at that value and go to the end.
        */
        cache.resize(nums.size(), -1);
        return dfs(nums, 0);
    }

    int dfs(std::vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }

        if (cache[i] != -1) return cache[i];
        int b = dfs(nums, i + 1);
        int a = nums[i] + dfs(nums, i + 2);
        cache[i] = std::max(a, b);
        return cache[i];
    }
};
