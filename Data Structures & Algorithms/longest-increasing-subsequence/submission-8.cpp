class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            0 1 0 3 2 3
            monotonic stack doesnt work

            DP:
            start at the end and ask what is the longest increasing subsequence
            we can make starting from that index
            initialise dp array at 1
            if current element is lower than the next, add that to the current
            dp element

            loop from the end of the array, and for each index i and iterate to the
            next element that is strictly greater than it and add its dp result to the
            current dp result (should be 1) O(n^2)

            9 1 4 2 3 3 7
                2 3 2 2 1
        */

        std::vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            int j = i + 1;
            int lis = 0;
            while (j < nums.size()) {
                if (nums[i] < nums[j]) {
                    lis = std::max(dp[j], lis);
                }
                j++;
            }
            dp[i] += lis;
            res = std::max(res, dp[i]);
        }
        return res;
    }
};  
