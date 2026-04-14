class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
           Track curr min and curr max initialise to 1
           multuply current min and max to nums[i]
           curr min is the min of current max * num and num * current min
           if we see a 0 reset curr min and max and continue
           keep global total tied to each curr max result

           curr_min -24
           curr_max -24
        */

        int curr_min = 1;
        int curr_max = 1;
        int res = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                curr_min = 1;
                curr_max = 1;
                res = std::max(res, 0);
                continue;
            }
            int temp = curr_min * nums[i];
            curr_min = std::min(std::min(temp, curr_max * nums[i]), nums[i]);
            curr_max = std::max(std::max(temp, curr_max * nums[i]), nums[i]);
            res = std::max(curr_max, res);
        }

        return res;
    }
};
