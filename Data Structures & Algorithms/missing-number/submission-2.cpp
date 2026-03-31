class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            loop through the nums array
            exclusive or each element
            if the output is 0 then all elements are in the nums set (x)
            the output will be the number at the end of the exclusive or
        */
        int output = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            output ^= i ^ nums[i];
        }
        return output;
    }
};
