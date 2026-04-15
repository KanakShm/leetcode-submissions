class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
            go through the array backwards
            for every value in your dp hashset
                insert the current nums value + the value in the dp
            return if we find the target
        */

        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
        }

        if (total % 2 != 0) return false;
        total /= 2;

        std::unordered_set<int> dp;
        dp.insert(0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            std::unordered_set<int> new_dp;
            for (int t : dp) {
                int val = t + nums[i];
                if (val == total) return true;
                new_dp.insert(val);
                new_dp.insert(t);
            }
            dp = new_dp;
        }
        return false;
    }
};
