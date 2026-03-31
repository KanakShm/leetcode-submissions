class Solution {
public:
    std::vector<int> cache_left;
    std::vector<int> cache_right;
    int rob(vector<int>& nums) {
        /*
            Dynamic Programming:
            Decision Tree:
            you can rob the house and move two spaces
            you can not rob the house and move one space

            1 Before:
            last element connects to the first

            Base Case:
            Go through array twice
        */
        cache_left.resize(nums.size(), -1);
        cache_right.resize(nums.size(), -1);
        std::vector<int> left;
        std::vector<int> right;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                left.push_back(nums[i]);
            } else if (i == nums.size() - 1) {
                right.push_back(nums[i]);
            } else {
                left.push_back(nums[i]);
                right.push_back(nums[i]);
            }
        }

        return std::max(dfs(left, 0, cache_left), dfs(right, 0, cache_right));
    }

    int dfs(std::vector<int>& nums, int i, std::vector<int>& cache) {
        if (i >= nums.size()) {
            return 0;
        }

        if (cache[i] != -1) return cache[i];
        int a = dfs(nums, i + 1, cache);
        int b = nums[i] + dfs(nums, i + 2, cache);
        cache[i] = std::max(a, b);
        return cache[i];
    }
};
