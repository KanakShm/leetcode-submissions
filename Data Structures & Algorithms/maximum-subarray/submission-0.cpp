class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
            sliding window technique where we increase our window size
            until the current sum becomes negative. Update left to right++ and right to right++

            At that point, we know that any subarray we would have calculated would
            be stored in a max sum global variable and and ensure that if any element that
            gets added on too this subarray would only decrease its value.
        */

        int max = INT_MIN;
        int curr_sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            curr_sum += nums[i];
            max = std::max(max, curr_sum);

            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }

        return max;
    }
};
