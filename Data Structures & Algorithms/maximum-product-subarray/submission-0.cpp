class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            Keep track of a local max and min
            keep updating as we iterate once through the array
        */

        int local_max = 1;
        int local_min = 1;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = local_max;
            local_max = std::max(std::max(local_max * nums[i], local_min * nums[i]), nums[i]);
            local_min = std::min(std::min(temp * nums[i], local_min * nums[i]), nums[i]);
            res = std::max(local_max, res);
        }
        return res;
    }
};
