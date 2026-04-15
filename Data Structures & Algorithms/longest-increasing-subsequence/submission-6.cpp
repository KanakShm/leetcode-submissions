class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            choose the next element if it is greater than the current
            else iterate through the entire nums

            keep track of index i as state variable and fill it with
            longest increasing subsequence from that index

            7 -> 1
            3 7
            3 7 
            2 [3]
            4 [7]
            1 + [2]
            9

            start from the end and iterate backwards and for each element iterate 
            forward to the first element that is greater than itself and return its
            1 + dp and save it to the current dp[i]

            return dp[0]
                        
                 2 3 2 2 1                                           
            [9,1,4,2,3,3,7]
        */

        std::vector<int> dp(nums.size(), 1);
        dp[nums.size() - 1] = 1;
        int res = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    dp[i] = std::max(1 + dp[j], dp[i]);
                    res = std::max(dp[i], res);
                }
            }
        }

        return res;
    }
};
