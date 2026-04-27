class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
            maintain a prefix sum
            2 -1 1 2
            0  2 1 2 4
            current sum - something in map = k
            current sum - k = something in map

            create a hashmap that maps elements with their frequency
            maintain a running sum. If we have seen this running sum - k in the map
            then add to count
        */

        int res = 0;
        int sum = 0;
        std::unordered_map<int, int> prefix_sum;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[sum]++;
            sum += nums[i];

            if (prefix_sum.find(sum - k) != prefix_sum.end()) {
                res += prefix_sum[sum - k];
            }
        }

        return res;
    }
};