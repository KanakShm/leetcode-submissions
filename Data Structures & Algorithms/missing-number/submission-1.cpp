class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            array where the i has value nums[i]
            array[nums[i]] = nums[i]
            iterate through the array and return the i that is 0
        */
        std::vector<int> sorted(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sorted[nums[i]] = nums[i];
        }

        for (int i = 1; i < sorted.size(); ++i) {
            if (sorted[i] == 0) {
                return i;
            }
        }

        return 0;
    }
};
