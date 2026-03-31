class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*

            Brute force is to look at each element and construct
            every sub array and choose the length that is smalles and more than target
            this is n^2

            Maintain sliding window:
            initialise left and right at 0 
            move right forward one space and add to the total
            update global res once we hit the target
            if we are smaller than the target increment right forward
            if we are larger increment left forward
            if left = right move both forward
        */
        int res = INT_MAX;
        int left = 0;
        int right = 0;

        int subarr = nums[left];
        while (left < nums.size()) {
            if (subarr >= target) {
                res = std::min(right - left + 1, res);
                subarr -= nums[left];
                left++;
            } else if (right < nums.size() - 1) {
                right++;
                subarr += nums[right];
            } else {
                subarr -= nums[left];
                left++;
            }
        }
        if (res == INT_MAX) {
            res = 0;
        }
        return res;
    }
};