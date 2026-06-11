class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*  
            i  j k
            -1,0,1,2,-1,-4

            sort the arra
            anchor i
            start j = i + 1
            start k at the end
            if sum == 0 then append and increment
            if sum < 0 then increment j
            if sum > 0 decrement k
        */

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0. && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return res;
    }
};
