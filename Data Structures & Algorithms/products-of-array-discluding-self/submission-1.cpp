class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            arr1 = [1, 1, 2, 8]
            arr2 = [48, 24, 6, 1]
        */

        std::vector<int> arr1(nums.size(), 1);
        std::vector<int> arr2(nums.size(), 1);

        int prev_mult = 1;
        int post_mult = 1;

        for (int i = 0; i < nums.size(); ++i) {
            arr1[i] = prev_mult;
            prev_mult *= nums[i];
        }
        std::cout << std::endl;

        for (int i = nums.size() - 1; i >= 0; i--) {
            arr2[i] = post_mult;
            post_mult *= nums[i];
        }

        std::vector<int> output;
        for (int i = 0; i < nums.size(); ++i) {
            output.push_back(arr1[i] * arr2[i]);
        }

        return output;
    }
};
