class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            ignore all elements <= 0 and > nums.size() + 1
            mark them all as nums.size() + 2
            iterate through the updated nums and for each number in range 1 - nums.size()
                go to the respective index and mark it as negative
            
            make this 1 indexed
            then iterate through the array and return the index of the first number that is 
            not negative

            1 2 3 4
        */

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0 || nums[i] > nums.size()) {
                nums[i] = nums.size() + 2;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (std::abs(nums[i]) > 0 && std::abs(nums[i]) <= nums.size() &&
                nums[std::abs(nums[i]) - 1] > 0) {
                nums[std::abs(nums[i]) - 1] *= -1;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return i + 1;
        }

        return nums.size() + 1;
    }
};