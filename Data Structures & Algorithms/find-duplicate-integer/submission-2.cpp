class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
            iterate through the array
            for each element go to that index and mark it as a negative
            if we arrive at a duplicate number we will see that the current element is already negative
            return that element
        */

        for (int i = 0; i < nums.size(); ++i) {
            // we visit a num
            int num = nums[abs(nums[i]) - 1];
            if (num < 0) return std::abs(nums[i]);
            else (nums[std::abs(nums[i]) - 1] *= -1);
        }
    }
};
