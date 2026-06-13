class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*  
            sort the array every time we iterate to the next unique element
            quadruple for loop checking every possible combination
            
            i    j k   l
            -3 0 1 2 3 3

            anchor i and j, then start k j + 1, l at the end
            and loop inwards
            
            if sum > target, j--
            sum < target k++
            if sum = target, append and then move k to the next unique element
        */

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                    }
                }
            }
        }
        return res;
    }
};