class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
            loop through array
            keep xoring value and save the result

            011
            010 001
            011 010
        */
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result ^= nums[i];
        }
        return result;
    }
};
