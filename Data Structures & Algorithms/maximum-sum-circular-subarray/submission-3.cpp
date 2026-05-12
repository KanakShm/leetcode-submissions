class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /*
            -2,4,-5,4,-5,9,4,-2,4,-5,4,-5,9,4
            only choose from 7 elements and start max nums.size()

            maintain a running sum
            if the value becomes negative increment left pointer up until the
            value is positive
            stop when r is == nums2 size

            l                     r
            10,-3,-4,7,6,5,-4,-1, 10,-3,-4,7,6,5,-4,-1
        */

        std::vector<int> nums2 = nums;
        for (int i = 0; i < nums.size(); ++i) {
            nums2.push_back(nums[i]);
        }

        int left = 0;
        int right = 0;
        int running_sum = 0;
        int res = INT_MIN;
        while (right < nums2.size()) {
            while (right - left >= nums.size() || (left < right && nums[left] <= 0)) {
                running_sum -= nums2[left];
                left++;
            }

            running_sum += nums2[right];
            right++;
            res = std::max(res, running_sum);
            
            while ((running_sum < 0 && left < right)) {
                running_sum -= nums2[left];
                left++;
            }


        }

        return res;
    }
};