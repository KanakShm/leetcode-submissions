class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            Prefix sum
            1 2 -3  4
            0 1  2 -6
        */

        int res = INT_MIN;
        int left_to_right = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                res = std::max(0, res);
                left_to_right = 1;
            } else {
                left_to_right *= nums[i];
                res = std::max(left_to_right, res);
            }
        }

        int right_to_left = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] == 0) {
                res = std::max(0, res);
                right_to_left = 1;
            } else {
                right_to_left *= nums[i];
                res = std::max(right_to_left, res);
            }
        }

        return res;
    }
};
