class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       /*
            Iterate through the array
            visit the index of the current number and mark it negative
            if at any point the index that you visit is a negative that means you have already visited
            it before
            return that number
       */

        for (int i = 0; i < nums.size(); ++i) {
            int idx = std::abs(nums[i]) - 1;
            if (nums[idx] < 0) return std::abs(nums[i]);
            nums[idx] *= -1;
        }

        return 0;
    }
};
